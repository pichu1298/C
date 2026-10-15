#include <stdio.h> // Include the standard input-output library for printf function
#include <types.h> // Include the types library for data type definitions

int main() {
    printf("Hello, World!\n"); // Print "Hello, World!" to the console
    calculateTax(); // Call the function to calculate tax
    calculatePolynomial(); // Call the function to calculate polynomial
    return 0; // Return 0 to indicate successful execution
}

//Chapter 2: Q 4
//Write a program that asks the user to enter a dollars and cents amount, then displays the amount with 5% tax added.

int calculateTax() {
    float amount = 0.0f;
    printf("Enter a dollar and cents amount: ");
    scanf("%f", &amount); // Read the user input for the amount
    printf("Your amount with 5 percent tax added is: $%.2f\n", amount * 1.05);
    return 0;
}

//Chapter 2: Q 5
//Write a program that asks the user to enter a value for x then displays the value of the following polynomial: 3x^5 + 2x^4, -5x^3 - x^2 +7x -6

int calculatePolynomial(){
    float x = 0.0f;
    printf("Enter a value for x please: ");
    scanf("%f", &x); // Read the user input for x
    float result = 3 * (x * x * x * x * x) + 2 * (x * x * x * x) - 5 * (x * x * x) - (x * x) + 7 * x - 6; // Calculate the polynomial value
    printf("The value of the polynomial 3x^5 + 2x^4 - 5x^3 - x^2 + 7x - 6 for x = %f is: %f\n", x, result); // Print the result
    return 0;
}

//Chapter 3: Q 3

//Chapter 3: Q 4