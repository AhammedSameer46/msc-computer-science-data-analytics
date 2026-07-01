/*
 * Program: Check Prime Number using a User-Defined Function
 *
 * ALGORITHM:
 * 1. Define a function isPrime(int n) that returns 1 if n is
 *    prime and 0 if it is not.
 * 2. Inside the function, check divisibility from 2 to n/2.
 * 3. In main(), take input, call isPrime(), and print the
 *    appropriate message based on the returned value.
 *
 * EXPLANATION:
 * Functions that answer a yes/no question are usually written to
 * return an int, where 1 means "true" and 0 means "false". This
 * makes the calling code in main() very easy to read with a
 * simple if-statement.
 *
 * SAMPLE INPUT / OUTPUT:
 * Input : 13
 * Output: 13 is a Prime number
 *
 * Input : 15
 * Output: 15 is NOT a Prime number
 */

#include <stdio.h>

// Function prototype
int isPrime(int n);

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isPrime(num))            // function call used directly in condition
        printf("%d is a Prime number\n", num);
    else
        printf("%d is NOT a Prime number\n", num);

    return 0;
}

// Function definition: returns 1 if prime, 0 if not
int isPrime(int n) {
    if (n <= 1)
        return 0;   // 0, 1, and negatives are not prime

    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0)
            return 0;   // divisor found -> not prime
    }
    return 1;   // no divisors found -> prime
}
