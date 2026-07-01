/*
 * Program: Factorial of a Number (using while loop)
 *
 * ALGORITHM:
 * 1. Take a number N as input.
 * 2. Initialize fact = 1.
 * 3. While N > 0: multiply fact by N, then decrease N by 1.
 * 4. Print fact.
 *
 * EXPLANATION:
 * Factorial of N (N!) = N * (N-1) * (N-2) * ... * 1
 * A while loop keeps multiplying until the counter reaches 0.
 * We use a temporary variable so the original N is still
 * available for the final printf message.
 *
 * SAMPLE INPUT / OUTPUT:
 * Input : 5
 * Output: Factorial of 5 = 120
 */

#include <stdio.h>

int main() {
    int n, temp;
    long long fact = 1;   // long long to hold larger factorial values

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 0;
    }

    temp = n;
    while (temp > 0) {
        fact = fact * temp;
        temp--;   // decrease counter until it reaches 0
    }

    printf("Factorial of %d = %lld\n", n, fact);

    return 0;
}
