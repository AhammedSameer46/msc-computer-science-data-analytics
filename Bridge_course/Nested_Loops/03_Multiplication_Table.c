/*
 * Program: Print Multiplication Tables from 1 to N
 *
 * ALGORITHM:
 * 1. Take N as input (how many tables to print).
 * 2. Outer loop runs from i = 1 to N (which table).
 * 3. Inner loop runs from j = 1 to 10 (multiplying by 1 to 10).
 * 4. Print i x j = result for every combination.
 *
 * EXPLANATION:
 * The outer loop picks the base number for the table (1, 2, 3...N).
 * The inner loop always runs 10 times (1 to 10) to print that
 * table's standard 10 multiplication facts.
 *
 * SAMPLE INPUT / OUTPUT:
 * Input : 2
 * Output:
 * Table of 1:
 * 1 x 1 = 1
 * ...
 * 1 x 10 = 10
 *
 * Table of 2:
 * 2 x 1 = 2
 * ...
 * 2 x 10 = 20
 */

#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter N (number of tables to print): ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {           // which table (1, 2, 3...)
        printf("Table of %d:\n", i);
        for (j = 1; j <= 10; j++) {      // multiplier from 1 to 10
            printf("%d x %d = %d\n", i, j, i * j);
        }
        printf("\n");   // blank line between tables
    }

    return 0;
}
