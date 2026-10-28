#include <stdio.h>

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

int main(void) {
    problem_one();
    return 0;
}