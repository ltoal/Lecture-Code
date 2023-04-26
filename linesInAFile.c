// a C program to find the number of lines in a file
#include<stdio.h>
#include<cs50.h>
#include<stdlib.h>

int main(void) {
    // counter for our newlines
    int count = 0;
    // pointer to our file
    FILE *fp = fopen("fileName.txt", "r");

    // make sure file exists
    if(fp == NULL) {
        printf("couldn't open file\n");
        return 1;
    }

    // keep track of current character
    char c = fgetc(fp);

    while(c != EOF) {
        if(c == '\n') {
            count++;
        }
        c = fgetc(fp);
    }

    printf("File has %d lines\n", count);

    fclose(fp);
}
