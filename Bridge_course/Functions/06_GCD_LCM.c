/*
 * Program: Find GCD and LCM of Two Numbers using Functions
 *
 * ALGORITHM:
 * 1. Define gcd(int a, int b) using the Euclidean algorithm:
 *      while b != 0: (a, b) = (b, a % b)
 *      return a
 * 2. Define lcm(int a, int b) using the relationship:
 *      LCM(a,b) = (a * b) / GCD(a,b)
 * 3. In main(), take two numbers, call both functions, and
 *    print the results.
 *
 * EXPLANATION:
 * The Euclidean algorithm is an efficient way to find the
 * Greatest Common Divisor by repeatedly replacing the larger
 * number with the remainder of dividing it by the smaller number,
 * until the remainder becomes 0. Once we know the GCD, the LCM
 * can be calculated directly using the formula above, since
 * GCD(a,b) * LCM(a,b) = a * b.
 *
 * SAMPLE INPUT / OUTPUT:
 * Input : a = 12, b = 18
 * Output:
 * GCD of 12 and 18 = 6
 * LCM of 12 and 18 = 36
 */

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
