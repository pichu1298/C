#include <stdio.h>

//Chapter 4: Q6
/* European countries uses a 13 digit code,
known as a European Article Number (EAN) instead
of the 12 digit Universal Product Code (UPC) found
in North America. Earth EAN ends with a check digit,
just as a UPC does. The technique for calculating
the check digit is also similar... blah blah blah*/

void calculateCheckDigit(){
    int EAN[13] = {0};
    printf("Chapter 4: Q 6\n");
    printf("Enter a 12 digit of the EAN as a single number!");
    scanf("%d", &EAN[0]);

    int offset = -1;
    int firstStep = EAN[2+offset] + EAN[4 + offset] + EAN[6 + offset] + EAN[8+offset] + EAN[10 + offset] + EAN[12+offset];
    int secondStep = EAN[1+offset] + EAN[3 + offset] + EAN[5 + offset] + EAN[7+offset] + EAN[9 + offset] + EAN[11+offset];
    int thirdStep = (firstStep *3) + secondStep;
    int fourthStep = thirdStep -1;
    int fifthStep = fourthStep % 10;
    int checkDigit = 9 - fifthStep;
    printf("The check digit is: %d\n", checkDigit);
};



//Chapter 5: Q2

//Chapter 5: Q10



int main(){
    calculateCheckDigit();
    return 0;
}