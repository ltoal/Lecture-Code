#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct {
    int winner;
    int loser;
}
pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[]) {
    // Check for invalid usage
    if (argc < 2) {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX) {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++) {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++) {
        for (int j = 0; j < candidate_count; j++) {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++) {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++) {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks)) {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[]) {
    for(int i = 0; i < candidate_count; i++) {
        if(strcmp(name, candidates[i]) == 0) {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[]) {
    for(int i = 0; i < candidate_count; i++) {
        for(int j = i+1; j < candidate_count; j++) {
            preferences[ranks[i]][ranks[j]]++;
        }
    }
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void) {
    for(int i = 0; i < candidate_count; i++) {
        for(int j = i+1; j < candidate_count; j++) {
            if(preferences[i][j] > preferences[j][i]) {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            } else if(preferences[j][i] > preferences[i][j]) {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void) {
    for(int i = 0; i < pair_count - 1; i++) {
        int max = i;
        int max_support = preferences[pairs[max].winner][pairs[max].loser];
        for(int j = i+1; j < pair_count; j++) {
            //does pairs[j] have a bigger support difference than current max difference
            int support = preferences[pairs[j].winner][pairs[j].loser];
            if(support > max_support) {
                max = j;
                max_support = support;
            }
        }
        pair temp = pairs[i];
        pairs[i] = pairs[max];
        pairs[max] = temp;
    }
}

bool is_cycle(int winner, int loser) {
    //does our winner exist as a loser in a locked pair?
    bool found;
    //as long as we're not sure the winner is never a loser, loop
    //only loop while winner & loser are different
    //(if we found our winner somewhere else and updated the overall winner, stop)
    while(winner != loser && winner != -1) {
        //we haven't found our winner yet
        found = false;
        //look at all other canidates
        for(int i = 0; i < candidate_count; i++) {
            //if our winner is a loser compared to current candidate
            if(locked[i][winner]) {
                //then we've found them
                found = true;
                //and the actual winner could be the current candidate 
                winner = i;
            }
        }
        //if our winner is not a loser in any other locked pair
        //then we did not find them
        //use -1 to say 'they're not there, stop looping'
        if(found == false) {
            winner = -1;
        }
    }
    //if our winner is never a loser, there is no cycle
    if(winner == -1) {
        return false;
    } else {
        return true;
    }
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void) {
    //for every pair
   for(int i = 0; i < pair_count; i++) {
       //if this pair doesn't create a cycle
       if(!is_cycle(pairs[i].winner, pairs[i].loser)) {
           //this (winner, loser) pair can be locked
           locked[pairs[i].winner][pairs[i].loser] = true;
       }
   }
}

// Print the winner of the election
void print_winner(void) {
    for(int i = 0; i < candidate_count; i++) {
        //assume current candidate is the winner
        bool is_winner = true;
        //if current candidate is the loser in any locked pair
        //they're not actually the winner
        for(int j = 0; j < candidate_count; j++) {
            if(locked[j][i]) {
                is_winner = false;
            }
        }
        //only print current candidates's name if they are still
        //winner after checking everything
        if(is_winner == true) {
            printf("%s\n", candidates[i]);
        }
    }
}

