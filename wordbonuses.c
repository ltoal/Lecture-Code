#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    // call this ONCE
    srand(time(NULL));

    // update these values once per turn.
    int dw1 = rand() % 99;
    int dw2 = rand() % 99;
    int tw1 = rand() % 99;
    int tw2 = rand() % 99;

    // if dw1 < 15, player 1 landed on a double word tile
    if(dw1 < 15) {
        printf("Player 1 gets a double word bonus!\n");
    }

    // if tw1 < 3, player 1 landed on a triple word tile
    if(tw1 < 3) {
        printf("Player 1 gets a triple word bonus!\n");
    }

    // & so on for player 2
}
