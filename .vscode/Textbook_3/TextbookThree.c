#include <ctype.h>
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
    char phoneLetters[16] = "XXXXXXXXXX";
    //2 = ABC, 3 = DEF, 4 GHI, 5 JKL, 6 MNO, 7 PRS, 8 TUV, 9 WXY
    printf("Enter phone letters: ");
    scanf("%s", phoneLetters);

    int i = 0;

    while (phoneLetters[i] != '\0'){
        printf("This is phone letter checking %c\n", phoneLetters[i]);
        switch (phoneLetters[i]){
            case 'A':
            case 'B':
            case 'C':
                phoneLetters[i] = '2';
                break;

            case 'D':
            case 'E':
            case 'F':
                phoneLetters[i] = '3';
                break;

            case 'G':
            case 'H':
            case 'I':
                phoneLetters[i] = '4';
                break;

            case 'J':
            case 'K':
            case 'L':
                phoneLetters[i] = '5';
                break;

            case 'M':
            case 'N':
            case 'O':
                phoneLetters[i] = '6';
                break;

            case 'P':
            case 'R':
            case 'S':
                phoneLetters[i] = '7';
                break;

            case 'T':
            case 'U':
            case 'V':
                phoneLetters[i] = '8';
                break;
            case 'W':
            case 'X':
            case 'Y':
                phoneLetters[i] = '9';
                break;
            default:
                break;
        };
        //end of switch statement
        i++;
    };
    //end of loop


    printf("This is your phone number %s\n", phoneLetters);
};

//Chapter 7: Q5
//SCRABBLE, change face values,c omput value of word by summining values of letters
void scrabble_calculator(){
    char word[] = "XXXXXXXXXXXXXXXXXX";
    printf("Enter a word: ");
    scanf("%s", word);

    int word_index = 0, score = 0;

    while (word[word_index] != '\0'){
        
        //switch statement below
        switch (toupper((word[word_index]))){
            case 'A':
            case 'E':
            case 'I':
            case 'L':
            case 'N':
            case 'O':
            case 'R':
            case 'S':
            case 'T':
            case 'U':
                score += 1;
                break;

            case 'D':
            case 'G':
                score += 2;
                break;

            case 'B':
            case 'C':
            case 'M':
            case 'P':
                score += 3;
                break;

            case 'F':
            case 'H':
            case 'V':
            case 'W':
            case 'Y':
                score += 4;
                break;

            case 'K':
                score += 5;
                break;

            case 'J':
            case 'X':
                score += 8;
                break;

            case 'Q':
            case 'Z':
                score += 10;
                break;

            default:
                score += 0;
                break;
        };
        //end of switch statement
        word_index++;
        
    };
    //end of while statement

    printf("Scrabble value: %d\n", score);

}





int main() {
    //Chapter 6: Q2
    int m,n;
    printf("Enter two positive integers (put a space between the two values): ");
    scanf("%d %d", &m, &n);
    calculateGCD(m, n);

    //Chapter 6: Q3
    reduceFraction();

    //Chapter 7: Q4
    phoneNumberConversion();

    //Chapter 7: Q5
    scrabble_calculator();

    return 0;
}