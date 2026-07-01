/*
 * Program: Print a Right-Angled Triangle Star Pattern
 *
 * ALGORITHM:
 * 1. Take number of rows N as input.
 * 2. Outer loop runs from i = 1 to N (controls the row).
 * 3. Inner loop runs from j = 1 to i, printing a '*' each time.
 * 4. Print a newline after each row.
 *
 * EXPLANATION:
 * Similar to the number pyramid, but instead of printing numbers,
 * we print the '*' character. Row i contains exactly i stars.
 *
 * SAMPLE INPUT / OUTPUT:
 * Input : 5
 * Output:
 * *
 * * *
 * * * *
 * * * * *
 * * * * * *
 */

#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter number of rows: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {        // controls the row number
        for (j = 1; j <= i; j++) {    // prints i stars in row i
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}
