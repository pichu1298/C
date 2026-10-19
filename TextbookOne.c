#include <stdio.h>




//Chapter 2: Q 4
//Write a program that asks the user to enter a dollars and cents amount, then displays the amount with 5% tax added.

void calculateTax() {
    printf("Chapter 2: Q 4\n");
    float amount = 0.0f;
    printf("Enter a dollar and cents amount: ");
    scanf("%f", &amount); // Read the user input for the amount
    printf("Your amount with 5 percent tax added is: $%.2f\n", amount * 1.05f);
}

//Chapter 2: Q 5
//Write a program that asks the user to enter a value for x then displays the value of the following polynomial: 3x^5 + 2x^4, -5x^3 - x^2 +7x -6

void calculatePolynomial(){
    printf("Chapter 2: Q 5\n");
    float x = 0.0f;
    printf("Enter a value for x please: ");
    scanf("%f", &x);
    float result = (3 * (x * x * x * x * x) + 2 * (x * x * x * x) - 5 * (x * x * x) - (x * x) + 7 * x - 6); // Calculate the polynomial value
    printf("The value of the polynomial 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 for x = %f is: %f\n", x, result); // Print the result
}

//Chapter 3: Q 3
/*Books are identified by an International Standard Book Number (ISBN). 
ISBNs assigned after January 1, 2007 contains 13 digits, arranged in five groups
such as 978-0-393-97950-3. (Older ISBNs use 10 digits.) The first group
(the GSI prefix) is currently either 978 or 979. Th egroup identifier specifies
the ... Blah blah blah. Write a program that breaks down an ISBN entered by the user*/

void isbnBreakdown(){
    printf("Chapter 3: Q 3\n");
    char isbn[31] = {0};
    char GSI_prefix[15] = {0}, group_identifier[15] = {0}, publisher_code[15] = {0}, item_number[15] = {0}, check_digit[15] = {0};
    printf("Enter an ISBN number: ");
    scanf("%s", isbn); // Read the user input for ISBN
    if (isbn[0] == '\0') {
        printf("No ISBN entered.\n");
        return;
    }
    int index_isbn = 0, GSI_index = 0, group_index = 0, publisher_index = 0, item_index = 0, check_index = 0, overall_index = 0;

    while (isbn[index_isbn] != '\0'){
        if (isbn[index_isbn] == '-'){
            overall_index+=1;
        }

        else if (overall_index == 0){
            GSI_prefix[GSI_index] = isbn[index_isbn];   
            GSI_index+=1;
        }

        else if (overall_index == 1){
            group_identifier[group_index] = isbn[index_isbn];
            group_index+=1;
        }

        else if (overall_index == 2){
            publisher_code[publisher_index] = isbn[index_isbn];
            publisher_index+=1;
        }

        else if (overall_index == 3){
            item_number[item_index] = isbn[index_isbn];
            item_index+=1;
        }

        else if (overall_index == 4){
            check_digit[check_index] = isbn[index_isbn];
            check_index+=1;
        }
        index_isbn+=1;
    }

    printf("GSI Prefix: %s\n", GSI_prefix);
    printf("Group Identifier: %s\n", group_identifier);
    printf("Publisher Code: %s\n", publisher_code);
    printf("Item Number: %s\n", item_number);
    printf("Check Digit: %s\n", check_digit);
}


//Chapter 3: Q 4
//Write a program that prompts the user to enter a telephone number in the form (xxx) xxx-xxxx and then displays the number in the form xxx.xxx.xxxx

void telephoneNumber(){
    printf("Chapter 3: Q 4\n");
    char phone[] = {"(555) 555-5555"};

    char first_half[] = {"555"};
    char second_half[] = {"555"};
    char third_half[] = {"5555"};


    int phoneIndex =0, partIndex = 0, first_half_index = 0, second_half_index = 0, third_half_index = 0;


    printf("Enter a telephone number in the form (xxx) xxx-xxxx: ");
    scanf(" %[^\n]", phone);

    /* let me write out in steps wha tto do..
    1. Read the telephone number,
    2. Store the first three digits,
    3. Store the second three digits,
    4. Store the last four digits
    5. print the formatted number...*/

    while (phone[phoneIndex] != '\0') {

        if (phone[phoneIndex] == '(' || phone[phoneIndex] == ')' || phone[phoneIndex] == ' ' || phone[phoneIndex] == '-') {
            if (phoneIndex == 4 || phoneIndex == 9) {
                partIndex++; // Move to the next part after the closing parenthesis
            }
            // Skip these characters
            phoneIndex++;
            continue;
        }
        
        if (partIndex == 0) {
            first_half[first_half_index] = phone[phoneIndex];
            first_half_index++;
        } else if (partIndex == 1) {
            second_half[second_half_index] = phone[phoneIndex];
            second_half_index++;
        } else if (partIndex == 2) {
            third_half[third_half_index] = phone[phoneIndex];
            third_half_index++;
        }
        phoneIndex++;
    }
    printf("The telephone number in the form xxx.xxx.xxxx is: %s.%s.%s", first_half, second_half, third_half);
}

void assignmentOne() {
    printf("Assignment One is running\n");
    calculateTax(); // Call the function to calculate tax
    calculatePolynomial(); // Call the function to calculate polynomial
    isbnBreakdown(); // Call the function to break down ISBN
    telephoneNumber(); // Call the function to format telephone number
}

int main() {
    assignmentOne(); // Call the assignmentOne function to execute the program
    return 0;
}