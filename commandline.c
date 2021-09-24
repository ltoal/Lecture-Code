#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[]) {
    //if the user gave us their name
    if(argc == 2) {
        printf("hello, %s\n",argv[1]);
        for(int i = 0; i < 4; i++) {
            //strings are arrays, so we can look at every character
            printf("%c\n",argv[1][i]);
        }
    } else {
        printf("hello, world\n");
    }
}
