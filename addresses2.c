// Prints a string

#include <cs50.h>
#include <stdio.h>

int main(void) {
    //print a string
    string s = "HI!";
    printf("%s\n", s);

    //print location of string
    printf("%p\n", s);
    
    //which is different from the location of the pointer
    printf("%p\n", &s);

    //print location of string and locations of individual chars
    printf("%p\n", s);
    printf("%p\n", &s[0]);
    printf("%p\n", &s[1]);
    printf("%p\n", &s[2]);
    printf("%p\n", &s[3]);

    //print a string's characters
    printf("%c\n", s[0]);
    printf("%c\n", s[1]);
    printf("%c\n", s[2]);

    //we don't even need the cs50 library
    char *s = "HI!";
    printf("%c\n", s[0]);
    printf("%c\n", s[1]);
    printf("%c\n", s[2]);

    //pointers are just numbers
    printf("%c\n", *s);
    printf("%c\n", *(s+1));
    printf("%c\n", *(s+2));

    //we can do this with other arrays
    int numbers[] = {4, 6, 8, 2, 7, 5, 0};

    printf("%i\n", *numbers);
    printf("%i\n", *(numbers+1));
    printf("%i\n", *(numbers+2));
    printf("%i\n", *(numbers+3));
    printf("%i\n", *(numbers+4));
    printf("%i\n", *(numbers+5));
    printf("%i\n", *(numbers+6));
}
