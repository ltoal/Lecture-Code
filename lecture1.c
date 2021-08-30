#include <stdio.h>
#include <cs50.h>

int main(void) {
   //integer variables
   int counter = 0;
   printf("counter is %d\n",counter);
   counter = counter+1;
   printf("counter is %d\n",counter);
   counter += 1;
   printf("counter is %d\n",counter);
   counter++;
   printf("counter is %d\n",counter);
   
   //conditionals
   if(counter < 10) {
       printf("counter is less than 10\n");
   } else if (counter > 10) {
       printf("counter is greater than 10\n");
   } else {
       printf("counter is equal to 10\n");
   }
   
   //loops
   //while(true) {
     //printf("hello, world\n");
   //}
   
   int i = 0;
   while (i < 50) {
       printf("hello, world\n");
       i++;
   }
   
   int answer;
   do {
       answer = get_int("Number greater than 50: ");
   }
   while(answer <= 50);
}
