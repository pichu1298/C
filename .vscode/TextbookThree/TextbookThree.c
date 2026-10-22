#include <stdio.h>
//Chapter 6: Q2
/* Write a program that asks the user
to enter two integers , then calculates
and displays their greatest common divisor*/

int calculateGCD(int m ,int n){
    // printf("Enter two positive integers (put a space between the two values): ");
    // scanf("%d %d", &m, &n);

    // Calculate GCD using Euclidean algorithm
    //If n is 0, quit loop, m is GCD
    //Remainder when m/n...
    //n is m and remainder is n
    //repeat until n is zero.

    while (n!= 0){
        int remainder = m%n;
        m = n;
        n = remainder;  
    };
    printf("The GCD is %d\n", m);
    return m;
};

//Chapter 6: Q3
//reduce fraction to lowest terms

void reduceFraction(){
    int numerator, denominator;
    printf("Enter a fraction!");
    scanf("%d/%d", &numerator, & denominator);
    int GCD = calculateGCD(numerator, denominator);
    printf("Your reduced fraction is %d/%d", numerator/GCD, denominator/GCD);
};


//Chapter 7: Q4
//convert alphabetic phone number into numeric form

void phoneNumberConversion(){
    char phoneLetters[11] = "XXXXXXXXXX";
    //2 = ABC, 3 = DEF, 4 GHI, 5 JKL, 6 MNO, 7 PRS, 8 TUV, 9 WXY
    printf("Enter phone letters: ");
    scanf("%c", &phoneLetters);
};

//Chapter 7: Q5





int main() {
    //Chapter 6: Q2
    int m,n;
    printf("Enter two positive integers (put a space between the two values): ");
    scanf("%d %d", &m, &n);
    calculateGCD(m, n);

    //Chapter 6: Q3
    reduceFraction();

    //Chapter 7: Q4

    //Chapter 7: Q5


    return 0;
}