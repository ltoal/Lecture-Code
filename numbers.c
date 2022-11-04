#include<cs50.h>
#include<stdio.h>

int main(void) {
    int numbers[] = {3, 5, 26, 51, 4, 32, 33, 110};
    int sortedNumbers[] = {11, 15, 20, 42, 53, 60, 61, 63, 74};

    // linear search
    // what are we searching for?
    int searchingFor = 15;

    // how many items in the array?
    // (can also just use the number for something small like this)
    int arrayLength = sizeof(numbers)/sizeof(numbers[0]);

    //searching
    for(int i = 0; i < arrayLength; i++) {
        if(numbers[i] == searchingFor) {
            printf("Linear search found the number in array 1\n");
            return 0;
        }
    }
    printf("Number does not exist in array 1\n");
    //return 1;

    // binary search

    int first = 0;
    int last = arrayLength-1;
    int middle = (first+last)/2;

    // as long as there is more than one element in the list
    // we can keep dividing in half
    // that last element will be part of a one-element list
    // that is or isn't our thing
    while(first <= last) {
        if(sortedNumbers[middle] == searchingFor) {
            printf("Binary search found the number in array 2\n");
            break;
        } else if(sortedNumbers[middle] < searchingFor) {
            first = middle+1;
        } else { //sortedNumbers[middle] > searchingFor
            last = middle-1;
        }
        middle = (first+last)/2;
    }

    if(first > last) {
        printf("Number is not in array 2\n");
    }
}
