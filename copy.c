#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main(void) {
    char *s = get_string("enter a string s: ");

    char *t = malloc(strlen(s)+1);

    //make sure memory allocation succeeded
    if(t == NULL) {
        return 1;
    }

    // can copy characters individually
    // for(int i = 0; i < strlen(s)+1; i++) {
    //     t[i] = s[i];
    // }

    strcpy(t,s);

    printf("s: %s\n", s);
    printf("t: %s\n", t);

    if(strlen(t) > 0) {
        for(int i = 0; i < strlen(t); i++) {
            t[i] = toupper(t[i]);
        }
    }

    printf("s: %s\n", s);
    printf("t: %s\n", t);

    free(t);
}
