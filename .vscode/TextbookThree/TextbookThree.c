#include <stdio.h>
//Chapter 6: Q2
/* Write a program that asks the user
to enter two integers , then calculates
and displays their greatest common divisor*/

void calculateGCD(){
    int A, B;
    printf("Enter two positive integers (put a space between the two values): ");
    scanf("%d %d", &A, &B);

    // Calculate GCD using Euclidean algorithm

   if (A == 0){
    printf("The GCD is $d\n", B );
   }
   else if (B == 0){
    printf("The GCD is $d\n", A);
   }
   else{
    //divide the A and B to get a number and remainder...
    //Then we find the GCD of B and the remainder...
    //A is now B and B is now the remainder...
    //We continue the loop until we return to either B or A being 0,
    //then the non zero integer is the answer.

    while (A != 0 || B != 0){
        int R = A%B;
        A = A/B;
        B = R;
    }
    if (A == 0){
        printf("The GCD is %d\n", B);
    }
    else if (B == 0){
        printf("The GCD is %d\n", A);
    }
   }

}

//Chapter 6: Q3

//Chapter 7: Q4

//Chapter 7: Q5





int main() {
    calculateGCD()
    return 0;
}