#include<stdlib.h>
#include<stdio.h>

int main(void) {
    int *x = malloc(3 * sizeof(int));

    // valgrind will give an 'invalid write' message
    // when you try to access x[3]
    x[1] = 72;
    x[2] = 73;
    x[3] = 33;

    // with no free(x) call, valgrind will give
    // a 'bytes lost' warning, referencing
    // the malloc() call on line 5
}
