#include <cs50.h>
#include <stdio.h>

int main(void) {
    char c1 = 'H';
    char c2 = 'I';
    char c3 = '!';
    printf("%c%c%c\n",c1,c2,c3);
    
    string s = "HI!";
    printf("%s\n",s);
    printf("%c\n%c\n%c\n%c\n%c\n",s[0],s[1],s[2],s[3],s[4]);
}
