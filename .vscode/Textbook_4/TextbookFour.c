#include <stdio.h>

//Chapter 8: Q5
//Compounds monthly instead of annually!, balance should be annual intervals

#define NUM_RATES ((int) (sizeof(value) / sizeof(value[0])))
#define INITIAL_BALANCE 100.00

void original_interest(void) { // Runs the interest table using yearly steps.
    int i, low_rate, num_years, year; // i selects a rate; the others store input and track the year.
    double value[5]; // Holds one balance for each of the five interest rates.

    printf("Enter interest rate: "); // Ask for the first interest rate in the table.
    scanf("%d", &low_rate); // Read that rate into low_rate.
    printf("Enter number of years: "); // Ask how many years to show.
    scanf("%d", &num_years); // Read the number of years into num_years.

    printf("\nYears"); // Print the first column heading.
    for (i = 0; i < NUM_RATES; i++) { // Visit each array slot: i is 0, 1, 2, 3, then 4.
        printf("%6d%%", low_rate + i); // Print the rate for this slot (starting rate plus i).
        value[i] = INITIAL_BALANCE; // Start this rate's balance at $100.
    } // Finished printing the rate headings and initializing all five balances.
    printf("\n"); // Move to the next line after the headings.

    for (year = 1; year <= num_years; year++) { // Repeat once for each year, from 1 through num_years.
        printf("%3d", year); // Print the current year at the start of its row.
        for (i = 0; i < NUM_RATES; i++) { // Visit each rate's balance for this year.
            value[i] *= 1.0 + (low_rate + i) / 100.0; // Add this year's interest to the balance.
            printf("%7.2f", value[i]); // Print this rate's updated value with two decimal places.
        } // Finished updating and printing every rate for this year.
        printf("\n"); // Move to the next line before printing the following year.
    } // Finished printing all requested years.
} // End of original_interest.

void modified_interest(void) {
    int i, low_rate, num_years, year, month;
    double value[5];

    printf("Enter monthly interest rate: ");
    scanf("%d", &low_rate);
    printf("Enter number of years: ");
    scanf("%d", &num_years);

    printf("\n%6s", "Years");
    for (i = 0; i < NUM_RATES; i++) {
        printf("%10d%%", low_rate + i);
        value[i] = INITIAL_BALANCE;
    }
    printf("\n");

    for (year = 1; year <= num_years; year++) {
        for (month = 1; month <= 12; month++) {
            for (i = 0; i < NUM_RATES; i++) {
                value[i] *= 1.0 + (low_rate + i) / 100.0;
            }
        }
        printf("%6d", year);
        for (i = 0; i < NUM_RATES; i++) {
            printf("%10.2f", value[i]);
        }
        printf("\n");
    }
}



//Chapter 10: Q6
//Write a program that evaluates Reverse Polish Notation (RPN) expressions using a stack.
//Operands are single-digit integers, and the supported operators are +, -, *, /, and =.
//Push each operand onto the stack; when an operator appears, pop its operands, calculate,
//and push the result back. The = operator displays the result and clears the stack so the
//user can enter another expression. Stop when the user enters a character that is neither
//an operand nor an operator. Report stack overflow or not enough operands, then terminate.

#define STACK_SIZE 20

void rpn_evaluator(void) {
    char rpn[STACK_SIZE];
    int calculator[STACK_SIZE];
    int top = -1, character_index=0;
    printf("Enter an RPN expression: ");
    scanf("%s", &rpn);

    while (rpn[character_index] != '\0') {
        if (rpn[character_index] >= '0' && rpn[character_index] <= '9') {
            calculator[++top] = rpn[character_index] - '0';

            /* push number onto the stack */
        }
        else if (rpn[character_index] == '='){
            printf("Result: %d ", calculator[top]);
            return;
        }
        else {
            int right, left, result;
            right = calculator[top--];
            left = calculator[top--];

            switch (rpn[character_index]) {
                case '+':
                    result = left+right;
                    calculator[++top] = result;

                    /* handle addition */
                    break;
                case '-':
                    result = left-right;
                    calculator[++top] = result;
                    /* handle subtraction */
                    break;
                    /* other operators */
                case '*':
                    result = left*right;
                    calculator[++top] = result;
                    break;
                case '/':
                    result = left/right;
                    calculator[++top] = result;
                    break;
            }
        }
        //end of while loop
        character_index++;
    }
}



int main(void) {
    modified_interest();
    rpn_evaluator();
    return 0;
}