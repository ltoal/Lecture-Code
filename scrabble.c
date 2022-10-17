#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// store points for each letter in order
int points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// function prototype
int calculate_score(string word);

int main(void) {
    // get each player's word
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // get each word's score
    int score1 = calculate_score(word1);
    int score2 = calculate_score(word2);

    // decide who wins
    if (score1 > score2) {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2) {
        printf("Player 2 wins!\n");
    }
    else {
        printf("Tie!\n");
    }
}

int calculate_score(string word) {
    // a word has a score
    int score = 0;
    int len = strlen(word);

    // look at each character
    for (int i = 0; i < len; i++) {
        if (isupper(word[i])) {
            score = score + points[word[i] - 65];
        }
        else if (islower(word[i])) {
            score = score + points[word[i] - 97];
        }
    }

    return score;
}
