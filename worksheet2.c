#include<cs50.h>
#include<string.h>
#include<stdio.h>

// test questions one at a time by commenting out
// all other code
// substitute file names with the names of
// existing or non-existing files
// as necessary/as stated in the problem description

int main(void) {
    // question 4
    FILE *fp = fopen("fileName.txt", "r");
    fprintf(fp, "It is March now");
    fclose(fp);

    // question 5
    FILE *fp = fopen("fileName2.txt", "r");
    fprintf(fp, "It is March now");
    fclose(fp);

    // question 6
    FILE *fp = fopen("fileName2.txt", "r");

    if(fp == NULL) {
        printf("could not open file\n");
        return 1;
     }

    fprintf(fp, "It is March now");
    fclose(fp);


    // question 7
    FILE *fp = fopen("fileName.txt", "a");

    if(fp == NULL) {
        printf("could not open file\n");
        return 1;
     }

    fprintf(fp, "It is March now");
    fclose(fp);
}
