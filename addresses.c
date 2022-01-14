#include <stdio.h>

int main(void) {
    int n = 50;
  
    //print an integer
    printf("%i\n", n);

    //print the integer's address
    printf("%p\n", &n);
    
    //go to address and print integer
    printf("%i\n", *&n);
    
    //store and print address
    int *p = &n;
    printf("%p\n", p);
    printf("%i\n", *p);

}
