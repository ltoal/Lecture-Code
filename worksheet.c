#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

// includes the code for all six questions
// test one at a time by commenting out
// the other five, or else the program
// will not compile

int main(void) {
    // question 1
    char *s = "hello";
    char *p = s;
    printf("%p\n%p\n", p, s);

    // question 2
    char *s = "hello";
    char *p = s;
    printf("%c\n%c\n", *(p+3), s[1]);

    // question 3
    int var;
    void *ptr = &var;
    *ptr = 5;
    printf("var=%d and *ptr=%d\n",var,*ptr);

    // question 4
    char s[] = "computerscience";
    printf("%s", s + s[6] - s[8]);

    // question 5
    char *s= "hello";
    char *p = s;
    printf("%c\n%c", p[0], s[9]);
    s[2] = 'w';
    p[2] = 'w';
    printf("%s\n",s);

    // question 6
    int *ptr;
    int x;

    ptr = &x;
    *ptr = 0;

    printf("x = %d\n", x);
    printf("*ptr = %d\n", *ptr);

    *ptr += 5;
    printf("x  = %d\n", x);
    printf("*ptr = %d\n", *ptr);

    (*ptr)++;
    printf("x = %d\n", x);
    printf("*ptr = %d\n", *ptr);

}
