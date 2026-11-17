#include <stdio.h>
#include <ctype.h>


//problem one from md

void swap(int *x, int *y){
    int poof = *x;
    *x = *y;
    *y = poof;
};

void problem_one(void) {
    int x = 3, y = 9;
    printf("Before: x=%d y=%d\n", x, y);
     //call swap here
    swap(&x,&y);
    printf("After: x=%d y=%d\n", x, y);
}


//problem two from md
void minMax(int *arr, int n, int *min, int *max){
    //return the smallest and largest number?
    int temp_min = arr[0];
    int temp_max = arr[0];
    for (int i = 0; i< n; i++){
        if (temp_min > arr[i]){
            temp_min = arr[i];
        }
        if (temp_max < arr[i]){
            temp_max = arr[i];
        }
    }
    *min = temp_min;
    *max = temp_max;
}

void problem_two(void) {
    int data[5] = {4, -2, 9, 0, 7};
    int lo, hi;
    minMax(data, 5, &lo, &hi);
    printf("min = %d, max = %d\n", lo, hi);
}

//problem three from md

void reverseArray(int *arr, int n){
    int left, right;
    for (int i = 0; i< n/2; i++){
        left = arr[i];
        right = arr[n-i-1];

        arr[i] = right;
        arr[n-1-i] = left;

    }
}

void problem_three(void){
    int data[6] = {1,2,3,4,5,6};
    reverseArray(data, 6);
    for (int i = 0; i< 6; i++){
        printf("%d ", data[i]);
    }
    printf("\n");
}


//Chapter 11: Q1
//modify programming project 7 from Chapter 2 so that it includes the following function:
void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones){
    *twenties = dollars / 20;
    dollars %= 20;

    *tens = dollars / 10;
    dollars %= 10;

    *fives = dollars / 5;
    *ones = dollars % 5;
}

void payment(void){
    int dollars;
    int twenties, tens, fives, ones;

    printf("Enter a dollar amount: ");
    if (scanf("%d", &dollars) != 1 || dollars < 0) {
        printf("Please enter a nonnegative whole-dollar amount.\n");
        return;
    }

    pay_amount(dollars, &twenties, &tens, &fives, &ones);

    printf("$20 bills: %d\n", twenties);
    printf("$10 bills: %d\n", tens);
    printf(" $5 bills: %d\n", fives);
    printf(" $1 bills: %d\n", ones);
}


//Chapter 12: Q2
// Read a full message from the user and check whether its letters form a
// palindrome: the letters should read the same in either direction. Ignore
// every character that is not a letter.
//
// Sample interaction:
// Enter a message: He lived as a devil, eh?
// Palindrome
//
// Enter a message: Madam, I am Adam.
// Not a palindrome
//
// Part (a): Use integer indexes to track positions in the message while
// comparing letters from the beginning and the end.
// Part (b): Revise the solution to track those positions with pointers
// instead of integer indexes.

void chapter_twelve(){
    char palindrome[32] = "";
    printf("Enter a message: ");
    fgets(palindrome, sizeof palindrome, stdin);
    printf("you have palindrome value %s", palindrome);
    int palindrome_length = 0;

    for (int i = 0; palindrome[i] != '\0'; i++) {
        unsigned char ch = (unsigned char)palindrome[i];

        if (isalpha(ch)) {
        palindrome[palindrome_length] = (char)tolower(ch);
        palindrome_length++;
        }
    }
    palindrome[palindrome_length] = '\0';

    //note, need to edit array to get rid of spaces and remove non letter characters.

    for (int i = 0; i < palindrome_length/2; i++){
        if (palindrome[i] != palindrome[palindrome_length-i-1]){
            printf("Not a palindrome");
            return;
        }
    }
    printf("Palindrome\n");

}


int main(void) {
    //problem_one();
    //problem_two();
    //problem_three();
    payment();
    //chapter_twelve();
    return 0;
}