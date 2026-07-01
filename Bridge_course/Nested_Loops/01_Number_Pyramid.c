/*
 * Program: Print a Number Pyramid Pattern
 *
 * ALGORITHM:
 * 1. Take number of rows N as input.
 * 2. Outer loop runs from i = 1 to N (controls the row).
 * 3. Inner loop runs from j = 1 to i (controls numbers printed
 *    in that row).
 * 4. Print j, then move to a new line after each row.
 *
 * EXPLANATION:
 * The outer loop decides which row we are on. The inner loop
 * decides how many numbers to print on that row -- row 1 prints
 * 1 number, row 2 prints 2 numbers, and so on, forming a pyramid.
 *
 * SAMPLE INPUT / OUTPUT:
 * Input : 4
 * Output:
 * 1
 * 1 2
 * 1 2 3
 * 1 2 3 4
 */

#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter number of rows: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {          // outer loop -> controls row
        for (j = 1; j <= i; j++) {      // inner loop -> controls columns
            printf("%d ", j);
        }
        printf("\n");   // move to next row after inner loop finishes
    }

    return 0;
}
