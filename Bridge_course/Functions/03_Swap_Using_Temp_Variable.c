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
