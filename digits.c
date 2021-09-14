#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main(void) {
    long num = 378282246310005;
    int count = 0;
    //repeatedly divide number by ten until you hit 0
    //count is an integer so we don't worry about remainders
    //(an example of truncation working for us!)
    //total number of divisions = total number of digits
    while(num != 0) {
        num = num/10;
        count++;
    }
    printf("Digits in number: %i\n",count);
    
    //re-declare number - it was changed in the while loop
    num = 378282246310005;
    //first digit - divide number by 10^(total digits-1)
    int first_digit = num/pow(10,count-1);
    //second digit - divide number by 10^(total digits-2)
    //then subtract the tens
    int second_digit = num/pow(10,count-2) - (first_digit*10);

    printf("First digit: %i\n",first_digit);
    printf("Second digit: %i\n",second_digit);

}
