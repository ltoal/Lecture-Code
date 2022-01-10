#include <cs50.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>

int count_letters(string s);
int count_sentences(string s);
int count_words(string s);

int main(void) {
    //get text from user
    string s = get_string("Text: ");

    //get letters, words, sentences
    int letters = count_letters(s);
    int sentences = count_sentences(s);
    int words = count_words(s)+1;

    float calculate = 0.0588 * (100.0 * letters / words)
                      - 0.296 * (100.0 * sentences / words)
                      - 15.8;

    int index = round(calculate);

    if(index >= 16) {
        printf("Grade 16+\n");
    } else if (index < 1) {
        printf("Before Grade 1\n");
    } else {
        printf("Grade %i\n", index);
    }

}

int count_letters(string s) {
    int count = 0;
    int len = strlen(s);
    for(int i = 0; i < len; i++) {
        if(isalpha(s[i])) {
            count++;
        }
    }
    return count;
}

int count_sentences(string s) {
    int count = 0;
    int len = strlen(s);
    for(int i = 0; i < len; i++) {
        if(s[i] == '.' || s[i] == '!' || s[i] == '?') {
            count++;
        }
    }
    return count;
}

int count_words(string s) {
    int count = 0;
    int len = strlen(s);
    for(int i = 0; i < len; i++) {
        if(isspace(s[i])) {
        count++;
        }
    }
    return count;
}
