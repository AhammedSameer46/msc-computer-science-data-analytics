/*
 * Program: Print Pascal's Triangle
 *
 * ALGORITHM:
 * 1. Take number of rows N as input.
 * 2. Outer loop runs from i = 0 to N-1 (controls the row).
 * 3. Inner loop calculates and prints each value in row i using
 *    the binomial coefficient formula, updating it step by step:
 *      value starts at 1 for the first entry of the row
 *      value = value * (i - j) / (j + 1)  for each next entry
 * 4. Print a newline after each row.
 *
 * EXPLANATION:
 * Each number in Pascal's Triangle is the sum of the two numbers
 * directly above it. Instead of storing the whole triangle in an
 * array, we use the mathematical shortcut (binomial coefficient)
 * to calculate each value directly using a running product,
 * which keeps the program beginner-friendly with just loops.
 *
 * SAMPLE INPUT / OUTPUT:
 * Input : 5
 * Output:
 * 1
 * 1 1
 * 1 2 1
 * 1 3 3 1
 * 1 4 6 4 1
 */

#include <stdio.h>

int main() {
    int n, i, j;
    long long value;

    printf("Enter number of rows: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        value = 1;   // first value in every row is always 1

        // Print leading spaces for a nicer triangular look (optional)
        for (j = 0; j < n - i - 1; j++) {
            printf("  ");
        }

        for (j = 0; j <= i; j++) {
            printf("%lld ", value);
            // update value to the next binomial coefficient in the row
            value = value * (i - j) / (j + 1);
        }
        printf("\n");
    }

    return 0;
}
