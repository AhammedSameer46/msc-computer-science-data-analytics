/*
 * Program: Reverse the digits of a Number (using while loop)
 *
 * ALGORITHM:
 * 1. Take a number N as input.
 * 2. Initialize reversed = 0.
 * 3. While N != 0:
 *      digit = N % 10          (get last digit)
 *      reversed = reversed*10 + digit   (append it to result)
 *      N = N / 10              (remove last digit)
 * 4. Print reversed.
 *
 * EXPLANATION:
 * The modulus operator (%) extracts the last digit of a number.
 * Integer division (/) removes that last digit. By repeatedly
 * peeling off digits from the end and appending them to a new
 * number, we build the number in reverse order.
 *
 * SAMPLE INPUT / OUTPUT:
 * Input : 1234
 * Output: Reversed number = 4321
 */

#include <stdio.h>

int main() {
    int n, digit, reversed = 0, original;

    printf("Enter a number: ");
    scanf("%d", &n);

    original = n;

    // Work with a positive copy so the logic is simple;
    // we reapply the sign at the end if needed.
    if (n < 0) n = -n;

    while (n != 0) {
        digit = n % 10;              // extract last digit
        reversed = reversed * 10 + digit;  // build reversed number
        n = n / 10;                  // remove last digit
    }

    if (original < 0)
        reversed = -reversed;

    printf("Reversed number = %d\n", reversed);

    return 0;
}
