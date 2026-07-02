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
