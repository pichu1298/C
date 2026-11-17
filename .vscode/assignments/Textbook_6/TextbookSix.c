#include <stdio.h>
#include <ctype.h>
#include <string.h>

//Chapter 12: Q1
//Write a program that reads a mesage, then prints the reversa of the message:
//Hint: Read the message one character at a time (using getchar) and store
//characters in an array. stop reading when the array is full or the character read is '\n
//revise the program to use a pointer instead of an integer to keep track of the current
//position in the array

void question_one(){
    char message[100];
    char *ptr_message = message;
    int size_of_array = sizeof(message) / sizeof(message[0]);
    int i = 0;
    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);
    while (message[i] != '\0' && message[i] != '\n') {
        *(ptr_message + size_of_array - 1 - i) = message[i];
        i++;
    } //end of while loop
    printf("Reversed message: %s\n", ptr_message);
}



//Chapter 12: Q4
//Simpliyfy programming project 2(b) by taking advantage of the fact
//that an array name can be used as a pointer

void chapter_twelve(){
    char message[100];
    char cleaned[100];
    char reversed[100];
    int length = 0;

    printf("Enter a message: ");
    if (fgets(message, sizeof message, stdin) == NULL) {
        return;
    }

    for (char *p = message; *p != '\0'; p++) {
        unsigned char ch = (unsigned char)*p;

        if (isalpha(ch)) {
            cleaned[length++] = (char)tolower(ch);
        }
    }
    cleaned[length] = '\0';

    for (int i = 0; i < length; i++) {
        reversed[i] = cleaned[length - 1 - i];
    }
    reversed[length] = '\0';

    if (strcmp(cleaned, reversed) == 0) {
        puts("Palindrome");
    } else {
        puts("Not a palindrome");
    }
}

//Then answer the following
//Palindrome checker-  Build a cleaned copy of the string, 
//reverse a second copy, and compare them with strcmp.

int main(){
    question_one();
    chapter_twelve();
    return 0;
}