#include <stdio.h>

// Function prototype
void swap(int *a, int *b);

int main() {
    int x, y;

    printf("Enter first number: ");
    scanf("%d", &x);
    printf("Enter second number: ");
    scanf("%d", &y);

    printf("Before swap: a = %d, b = %d\n", x, y);

    swap(&x, &y);

    printf("After swap : a = %d, b = %d\n", x, y);

    return 0;
}

// Function definition: swaps values using addition/subtraction only
void swap(int *a, int *b) {
    *a = *a + *b;   // a now holds the sum of both
    *b = *a - *b;   // b becomes the original a
    *a = *a - *b;   // a becomes the original b
}
