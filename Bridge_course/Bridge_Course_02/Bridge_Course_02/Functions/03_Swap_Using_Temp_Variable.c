/*
 * Program: Swap Two Numbers using a Function (WITH a temp variable)
 * This is Logic 1 of 2 -- see 04_Swap_Without_Temp_Variable.c for Logic 2.
 *
 * ALGORITHM:
 * 1. Define a function swap(int *a, int *b) that takes POINTERS
 *    to the two variables (so it can modify the originals).
 * 2. Inside the function, store *a in a temp variable, put *b
 *    into *a, then put temp into *b.
 * 3. In main(), take two numbers and pass their ADDRESSES to swap().
 *
 * EXPLANATION:
 * If we passed the numbers normally (by value), the function would
 * only get copies, and swapping the copies would not affect the
 * originals in main(). By passing POINTERS (addresses), the
 * function can reach back into main()'s memory and change the
 * actual variables. This is called "pass by reference".
 *
 * SAMPLE INPUT / OUTPUT:
 * Input : a = 5, b = 10
 * Output:
 * Before swap: a = 5, b = 10
 * After swap : a = 10, b = 5
 */

#include <stdio.h>

// Function prototype -- takes pointers so it can modify original values
void swap(int *a, int *b);

int main() {
    int x, y;

    printf("Enter first number: ");
    scanf("%d", &x);
    printf("Enter second number: ");
    scanf("%d", &y);

    printf("Before swap: a = %d, b = %d\n", x, y);

    swap(&x, &y);   // pass addresses of x and y

    printf("After swap : a = %d, b = %d\n", x, y);

    return 0;
}

// Function definition: swaps values using a temporary variable
void swap(int *a, int *b) {
    int temp = *a;   // save value pointed to by a
    *a = *b;         // copy b's value into a's location
    *b = temp;       // copy the saved value into b's location
}
