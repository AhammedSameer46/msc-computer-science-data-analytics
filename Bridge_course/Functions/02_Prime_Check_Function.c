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
