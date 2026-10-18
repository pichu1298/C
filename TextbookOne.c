#include <stdio.h> // Include the standard input-output library for printf function
#include <types.h> // Include the types library for data type definitions

int main() {
    printf("Calculate Tax is running\n");
    calculateTax(); // Call the function to calculate tax
    printf("Calculate Polynomial is running\n");
    calculatePolynomial(); // Call the function to calculate polynomial
    printf("ISBN Breakdown is running\n");
    isbnBreakdown(); // Call the function to break down ISBN
    printf("Telephone Number Formatting is running\n");
    telephoneNumber(); // Call the function to format telephone number
    return 0; // Return 0 to indicate successful execution
}

//Chapter 2: Q 4
//Write a program that asks the user to enter a dollars and cents amount, then displays the amount with 5% tax added.

int calculateTax() {
    float amount = 0.0f;
    printf("Enter a dollar and cents amount: ");
    scanf("%.2f", &amount); // Read the user input for the amount
    printf("Your amount with 5 percent tax added is: $%.2f\n", amount * 1.05f);
    return 0;
}

//Chapter 2: Q 5
//Write a program that asks the user to enter a value for x then displays the value of the following polynomial: 3x^5 + 2x^4, -5x^3 - x^2 +7x -6

int calculatePolynomial(){
    float x = 0.0f;
    printf("Enter a value for x please: ");
    scanf("%f", &x); // Read the user input for x
    float result = (3 * (x * x * x * x * x) + 2 * (x * x * x * x) - 5 * (x * x * x) - (x * x) + 7 * x - 6); // Calculate the polynomial value
    printf("The value of the polynomial 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 for x = %f is: %f\n", x, result); // Print the result
    return 0;
}

//Chapter 3: Q 3
/*Books are identified by an International Standard Book Number (ISBN). 
ISBNs assigned after January 1, 2007 contains 13 digits, arranged in five groups
such as 978-0-393-97950-3. (Older ISBNs use 10 digits.) The first group
(the GSI prefix) is currently either 978 or 979. Th egroup identifier specifies
the ... Blah blah blah. Write a program that breaks down an ISBN entered by the user*/

int isbnBreakdown(){
    char isbn[20] = {0};
    int GSI_prefix[10], group_identifier[10], publisher_code[10], item_number[10], check_digit[10] = {0};
    printf("Enter an ISBN number: ");
    scanf("%s", isbn); // Read the user input for ISBN

    //need to somehow splice the digits per dash and print the specific stuff attached idk
    //not spliced,  but does this work?
    int i = 0;
    int part = 0;
    int array_part = 0;
    while (isbn[i] != '\0') {
        i+=1;
        if (isbn[i] == '-'){
            part+1;
            array_part = 0;
        }
        else if(part == 0){
            GSI_prefix[array_part]= isbn[i];
            array_part+1;
        }
        else if(part == 1){
            group_identifier[array_part]= isbn[i];
            array_part+1;
        }
        else if(part == 2){
            publisher_code[array_part]= isbn[i];
            array_part+1;
        }
        else if(part == 3){
            item_number[array_part]= isbn[i];
            array_part+1;
        }
        else if(part == 4){
            check_digit[array_part]= isbn[i];
            array_part+1;
        }
    }
}


//Chapter 3: Q 4
//Write a program that prompts the user to enter a telephone number in the form (xxx) xxx-xxxx and then displays the number in the form xxx.xxx.xxxx

int telephoneNumber(){
    char phone[14] = {0};
    char formattedPhone[12] = {0};
    printf("Enter a telephone number in the form (xxx) xxx-xxxx: ");
    scanf("%s", phone); // Read the user input for telephone number
    for (int i=1; i<sizeof(phone); i++){
        if (phone[i] == ' ' || phone[i] == '-'){
            formattedPhone[i-1] = '.';
        }
        else if (phone[i] == ')'){
            continue; //skip the closing parenthesis
        }
        else{
            formattedPhone[i-1] = phone[i];
        }
    }
    printf("The telephone number in the form xxx.xxx.xxxx is: %s\n", formattedPhone);
    return 0;
}