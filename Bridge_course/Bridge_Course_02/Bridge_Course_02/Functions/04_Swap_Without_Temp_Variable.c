/*
 * Program: Swap Two Numbers using a Function (WITHOUT a temp variable)
 * This is Logic 2 of 2 -- see 03_Swap_Using_Temp_Variable.c for Logic 1.
 *
 * ALGORITHM:
 * 1. Define a function swap(int *a, int *b) that takes pointers.
 * 2. Use arithmetic to swap without a third variable:
 *      *a = *a + *b
 *      *b = *a - *b   (this now equals the original *a)
 *      *a = *a - *b   (this now equals the original *b)
 *
 * EXPLANATION:
 * This is a classic trick: by adding the two numbers together first,
 * we can "extract" the original values back out using subtraction,
 * without ever needing a separate temp variable to hold a value.
 * Pointers are still required so the changes reflect back in main().
 *
 * SAMPLE INPUT / OUTPUT:
 * Input : a = 5, b = 10
 * Output:
 * Before swap: a = 5, b = 10
 * After swap : a = 10, b = 5
 *
 * NOTE: This arithmetic trick can overflow for very large numbers,
 * so the temp-variable method (Logic 1) is generally safer in
 * real-world code.
 */

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
