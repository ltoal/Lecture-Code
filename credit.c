#include<cs50.h>
#include<stdio.h>
#include<math.h>

int main(void) {
    // get number from user
    long creditCard = get_long("Enter credit card number: \n");

    //figure out how long it is
    long copy = creditCard;
    int numLength = 0;
    while(copy != 0) {
        copy = copy/10;
        numLength++;
    }

    //variables
    int checksum = 0;
    int firstDigit = creditCard/pow(10,numLength-1);
    int secondDigit = creditCard/pow(10,numLength-2) - (firstDigit*10);

    //iterate across all possible digits
    //reading left to right
    for(int i = numLength-1; i >= 0; i--) {
        //determine current digit value
        long digit = (creditCard/(long) pow(10,i)) % 10;

        //every other number starting with second to last
        //aka every number in a 10^odd number space
        //gets doubled
        if((i % 2) != 0) {
            //if doubled value < 10 (if the digit is < 5)
            //add it to checksum
            if(digit < 5) {
                checksum += 2 * digit;
            } else {
            //add the digits together before adding it to checksum
                checksum += ((2 * digit) % 10) + 1;
            }
        } else {
            //add every other digit to checksum
            checksum += digit;
        }
    }

    //check to make sure number has apporpriate number of digits
    if(numLength < 13 || numLength == 14 || numLength > 16) {
        //invalid legnth
        printf("INVALID\n");
    } else if((checksum % 10) != 0) {
        //invalid checksum
        printf("INVALID\n");
    } else if(firstDigit == 4 && (numLength == 13 || numLength == 16)) {
        //VISA
        printf("VISA\n");
    } else if(firstDigit == 3 && (secondDigit == 4 || secondDigit == 7) && numLength == 15) {
        //AMEX
        printf("AMEX\n");
    } else if(firstDigit == 5 && (secondDigit >= 1 && secondDigit <= 5) && numLength == 16) {
        //MASTERCARD
        printf("MASTERCARD\n");
    } else {
        printf("INVALID\n");
    }
}
