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
