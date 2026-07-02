#include <stdio.h>

// Function prototypes
int gcd(int a, int b);
int lcm(int a, int b, int gcdValue);

int main() {
    int num1, num2, gcdResult, lcmResult;

    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    gcdResult = gcd(num1, num2);
    lcmResult = lcm(num1, num2, gcdResult);

    printf("GCD of %d and %d = %d\n", num1, num2, gcdResult);
    printf("LCM of %d and %d = %d\n", num1, num2, lcmResult);

    return 0;
}

// Function definition: Euclidean algorithm for GCD
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;   // when b becomes 0, a holds the GCD
}

// Function definition: LCM using the GCD we already calculated
int lcm(int a, int b, int gcdValue) {
    return (a * b) / gcdValue;
}
