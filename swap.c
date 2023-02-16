#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

void swap(int *a, int *b);

int main(void) {

    // swapping integers
    // integers a, b, temp
    // temp = a
    // a = b
    // b = temp

    int a = 10;
    int b = 13;
    printf("a: %i, b: %i\n",a,b);
    //send addresses of a and b to swap
    swap(&a,&b);
    printf("a: %i, b: %i\n",a,b);

}

void swap(int *a, int *b) {
    // follow our pointers to initial a and b NOT copies
    int temp = *a;
    *a = *b;
    *b = temp;
}
