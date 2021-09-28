#include<cs50.h>
#include<stdio.h>
#include<float.h>
#include<stdlib.h>

int main(int argc, string argv[]) {

    //do we have the correct number of arguments
    if(argc != 4) {
        printf("Incorrect number of arguments. Usage: ./calc 4 + 5\n");
        return 1;
    }

    float first = atof(argv[1]);
    float second = atof(argv[3]);
    char op = argv[2][0];

    if(op == '+') {
        printf("%f\n",first+second);
    } else if(op == '-') {
        printf("%f\n",first-second);
    } else if(op == 'x') {
        printf("%f\n",first*second);
    } else if(op == '/') {
        printf("%f\n",first/second);
    } else if(op == '%') {
        int x = first/second;
        printf("%f\n",first-(second*x));
    } else {
        printf("invalid operator\n");
        return 1;
    }
}
