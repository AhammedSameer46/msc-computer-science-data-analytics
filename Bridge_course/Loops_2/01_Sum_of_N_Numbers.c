/*
 * Program: Sum of first N Natural Numbers
 *
 * ALGORITHM:
 * 1. Take N as input.
 * 2. Initialize sum = 0.
 * 3. Loop from i = 1 to N, adding i to sum each time.
 * 4. Print the final sum.
 *
 * EXPLANATION:
 * A "for" loop is the natural choice when we know exactly how many
 * times we want to repeat something (here, N times). On every
 * iteration we add the current value of i to a running total.
 *
 * SAMPLE INPUT / OUTPUT:
 * Input : 5
 * Output: Sum of first 5 natural numbers = 15   (1+2+3+4+5)
 */

#include <stdio.h>

int main() {
    int n, i, sum = 0;

    printf("Enter N: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        sum = sum + i;   // add current number to the running total
    }

    printf("Sum of first %d natural numbers = %d\n", n, sum);

    return 0;
}
