#include <stdio.h>

//Chapter 4: Q6
/* European countries uses a 13 digit code,
known as a European Article Number (EAN) instead
of the 12 digit Universal Product Code (UPC) found
in North America. Earth EAN ends with a check digit,
just as a UPC does. The technique for calculating
the check digit is also similar... blah blah blah*/

void calculateCheckDigit(){
    char EAN[13] = {0};
    printf("Chapter 4: Q 6\n");
    printf("Enter a 12 digit of the EAN as a single number!");
    scanf("%s", EAN);

    printf("The EAN you entered is: %s\n", EAN);

    int offset = -1;
    int firstStep = (EAN[2+offset]-'0') + (EAN[4 + offset]-'0') + (EAN[6 + offset]-'0') + (EAN[8+offset]-'0') + (EAN[10 + offset]-'0') + (EAN[12+offset]-'0');
    printf("The first step is: %d\n", firstStep);
    int secondStep = (EAN[1+offset]-'0') + (EAN[3 + offset]-'0') + (EAN[5 + offset]-'0') + (EAN[7+offset]-'0') + (EAN[9 + offset]-'0') + (EAN[11+offset]-'0');
    printf("The second step is: %d\n", secondStep);
    int thirdStep = (firstStep *3) + secondStep;
    int fourthStep = thirdStep -1;
    int fifthStep = fourthStep % 10;
    int checkDigit = 9 - fifthStep;
    printf("The check digit is: %d\n", checkDigit);
};



//Chapter 5: Q2
//write a program that asks the user for a 24-hour time, then displays the time in 12-hour form:

void convertTime(){
    char time[] = "12:00";
    char amPm[] = "AM";
    printf("Give me a time in 24 hour format (HH:MM): ");
    scanf("%s", time);
    printf("The time you entered is: %s\n", time);
    int hour = (time[0] - '0') * 10 + (time[1] - '0');
    if (hour >= 12) {
        amPm[0] = 'P';
    }
    if (hour == 0) {
        hour = 12;
    } else if (hour > 12) {
        hour -= 12;
    }

    printf("The time in 12 hour format is: %d:%c%c %s\n", hour, time[3], time[4], amPm);
}

//Chapter 5: Q10

void gradeConverter(){
    int grade = 0;
    printf("Enter a grade between 0 and 100: ");
    scanf("%d", &grade);
    printf("The grade you entered is: %d\n", grade);

    switch (grade/10){
        case 10:
            printf("The letter grade is: A\n");
            break;
        case 9:
            printf("The letter grade is: A\n");
            break;
        case 8:
            printf("The letter grade is: B\n");
            break;
        case 7:
            printf("The letter grade is: C\n");
            break;
        case 6:
            printf("The letter grade is: D\n");
            break;
        default:
            printf("The letter grade is: F\n");
    }
}


int main(){
    calculateCheckDigit();
    convertTime();
    gradeConverter();
    return 0;
}