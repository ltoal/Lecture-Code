#include <cs50.h>
#include <stdio.h>

int main(void) {
    int x = get_int("x: ");
    //long x = get_long("x: ");

    int y = get_int("y: ");
    //long x = get_long("y: ");

    printf("%i\n", x + y);
    //printf("%li\n", x + y);
}
