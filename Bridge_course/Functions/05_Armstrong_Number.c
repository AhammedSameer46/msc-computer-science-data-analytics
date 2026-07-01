/*
 * Program: Check Armstrong Number using a User-Defined Function
 *
 * ALGORITHM:
 * 1. Define isArmstrong(int n) that returns 1 or 0.
 * 2. Inside the function:
 *      - Count the number of digits in n.
 *      - For each digit, raise it to the power of (number of
 *        digits) and add it to a sum.
 *      - Compare sum with the original number.
 * 3. In main(), call the function and print the result.
 *
 * EXPLANATION:
 * An Armstrong number is a number that equals the sum of its own
 * digits each raised to the power of the number of digits.
 * Example: 153 = 1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153
 *
 * SAMPLE INPUT / OUTPUT:
 * Input : 153
 * Output: 153 is an Armstrong number
 *
 * Input : 123
 * Output: 123 is NOT an Armstrong number
 */

#include <stdio.h>
#include <math.h>   // for pow()

// Function prototype
int isArmstrong(int n);

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isArmstrong(num))
        printf("%d is an Armstrong number\n", num);
    else
        printf("%d is NOT an Armstrong number\n", num);

    return 0;
}

// Function definition: returns 1 if Armstrong number, else 0
int isArmstrong(int n) {
    int original = n, digitCount = 0, remainder;
    long long sum = 0;

    // Step 1: count number of digits
    int temp = n;
    if (temp == 0) digitCount = 1;
    while (temp != 0) {
        digitCount++;
        temp = temp / 10;
    }

    // Step 2: sum each digit raised to the power of digitCount
    temp = n;
    while (temp != 0) {
        remainder = temp % 10;
        sum += (long long) pow(remainder, digitCount);
        temp = temp / 10;
    }

    return (sum == original) ? 1 : 0;
}
