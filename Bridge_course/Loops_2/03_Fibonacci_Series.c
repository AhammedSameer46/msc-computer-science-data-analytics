/*
 * Program: Print Fibonacci Series up to N terms
 *
 * ALGORITHM:
 * 1. Take the number of terms N as input.
 * 2. Start with first = 0, second = 1.
 * 3. Print first, then repeat N-2 more times:
 *    next = first + second
 *    shift first = second, second = next
 * 4. Each new term is the sum of the previous two terms.
 *
 * EXPLANATION:
 * The Fibonacci sequence is 0, 1, 1, 2, 3, 5, 8, 13, ...
 * We use a for loop that runs N times, printing the current term
 * and then updating the two "tracking" variables for the next step.
 *
 * SAMPLE INPUT / OUTPUT:
 * Input : 7
 * Output: Fibonacci Series: 0 1 1 2 3 5 8
 */

#include <stdio.h>

int main() {
    int n, i, first = 0, second = 1, next;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");

    for (i = 1; i <= n; i++) {
        if (i == 1) {
            printf("%d ", first);
            continue;
        }
        if (i == 2) {
            printf("%d ", second);
            continue;
        }
        next = first + second;   // new term = sum of previous two
        printf("%d ", next);
        first = second;          // shift values forward
        second = next;
    }
    printf("\n");

    return 0;
}
