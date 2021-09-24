#include <cs50.h>
#include <stdio.h>

//our array length will never change
const int TOTAL_SCORES = 3;

int main(void) {
  //create and add numbers to array
  int scores[TOTAL_SCORES];
  scores[0] = 72;
  scores[1] = 73;
  scores[2] = 33;
  
  //print a single value from array
  printf("second score: %i\n",scores[1]);
  //print average of all values from array
  printf("average score: %f\n", (scores[0] + scores[1] + scores[2]) / 3.0);
  
  scores[2] = get_int("enter new third score: ");
  printf("new third score: %i\n",scores[2]);
  
  //replace values using a loop
  for(int i = 0; i<TOTAL_SCORES; i++) {
      scores[i] = get_int("Score: ");
  }
  
  //print new values
  for(int i = 0; i < TOTAL_SCORES; i++) {
      printf("Score %i: %i\n",i,scores[i]);
  }
  
  //use loops to calculate our average
  int sum = 0;
  for(int i = 0; i < TOTAL_SCORES; i++) {
      sum = sum + scores[i];
  }
  printf("New average: %f", sum / (float) TOTAL_SCORES);
 }
