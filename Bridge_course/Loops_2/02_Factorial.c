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
