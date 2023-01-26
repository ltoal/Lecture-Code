#include<stdio.h>
// #include<cs50.h>

int main(void) {
    //creating an integer value
    int n = 50;
    //printing value of integer variable
    printf("%i\n", n);
    //getting the address of where n is stored
    //and putting it in pointer variable p
    int *p = &n;
    //print the address using placeholder for a pointer
    printf("%p\n", p);

    //create a string using the cs50 library
    // string s = "HI!";
    // printf("%s\n", s);
    //create a string by pointing to the first character
    char *s2 = "Hello!";
    printf("%s\n", s2);
}
