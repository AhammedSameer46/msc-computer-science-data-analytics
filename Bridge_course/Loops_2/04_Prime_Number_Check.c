/*
 * Program: Check whether a number is Prime or Not (using for loop)
 *
 * ALGORITHM:
 * 1. Take a number N as input.
 * 2. A number is prime if it is greater than 1 and has no
 *    divisors other than 1 and itself.
 * 3. Loop from i = 2 to N/2 (or sqrt(N)) checking if N % i == 0.
 * 4. If any divisor is found, it's NOT prime. Otherwise, it IS prime.
 *
 * EXPLANATION:
 * We only need to check divisors up to N/2 because no number
 * greater than N/2 (other than N itself) can evenly divide N.
 * A flag variable keeps track of whether a divisor was found.
 *
 * SAMPLE INPUT / OUTPUT:
 * Input : 7
 * Output: 7 is a Prime number
 *
 * Input : 12
 * Output: 12 is NOT a Prime number
 */

#include <stdio.h>

int main() {
    int n, i, isPrime = 1;   // assume prime until proven otherwise

    printf("Enter a number: ");
    scanf("%d", &n);

    if (n <= 1) {
        isPrime = 0;   // 0, 1, and negative numbers are not prime
    } else {
        for (i = 2; i <= n / 2; i++) {
            if (n % i == 0) {
                isPrime = 0;   // found a divisor, so not prime
                break;         // no need to check further
            }
        }
    }

    if (isPrime)
        printf("%d is a Prime number\n", n);
    else
        printf("%d is NOT a Prime number\n", n);

    return 0;
}
