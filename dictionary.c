// Implements a dictionary's functionality

#include <stdbool.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Keep track of how many words I'm working with
int totalwords = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word) {
    // hash the word to figure out which list to look at
    unsigned int hashcode = hash(word);
    
    // keep track of our current node
    node *currentnode = table[hashcode];
    while(currentnode != NULL) {
        if(strcasecmp(currentnode->word, word)== 0) {
            return true;
        }
        
        // maybe it's in the next node
        currentnode = currentnode->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word) {
    // lots of possibilities here!
    return 0;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary) {
    //open dictionary
    FILE *file = fopen(dictionary, "r");
    
    //make sure file was opened
    if(file == NULL) {
        return false;
    }
    
    while(true) {
        node *newnode = malloc(sizeof(node));
        if(newnode == NULL) {
            return false;
        }
        
        //read string into node, compare to EOF
        if(fscanf(file, "%s", newnode->word) == EOF) {
            break;
        }
        
        //hash word to determine index of array where node belongs
        unsigned int hashcode = hash(newnode->word);
        
        //add node to the list at appropriate index
        newnode->next = table[hashcode];
        table[hashcode] = newnode;
        
        //update size of dictionary
        totalwords++;
    }
    
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void) {
    return totalwords;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void) {
    // loop through array, deleting all lists
    for(int i = 0; i < N; i++) {
        empty_list(table[i]);
        return true;
    }
    return false;
}

void empty_list(node *beginning) {
    // if the list doesn't exist, awesome! it's all freed!
    if(beginning == NULL) {
        return;
    }
    empty_list(beginning->next);
    free(beginning);
}
