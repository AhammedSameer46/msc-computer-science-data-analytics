/*
 * Program: Print Floyd's Triangle
 *
 * ALGORITHM:
 * 1. Take number of rows N as input.
 * 2. Keep a counter variable "num" starting at 1.
 * 3. Outer loop runs from i = 1 to N (controls row).
 * 4. Inner loop runs from j = 1 to i, printing "num" and then
 *    incrementing it each time.
 * 5. Move to a new line after each row.
 *
 * EXPLANATION:
 * Unlike the number pyramid (which resets to 1 every row), Floyd's
 * Triangle keeps counting up continuously across all rows. We use
 * a single counter variable that is never reset between rows.
 *
 * SAMPLE INPUT / OUTPUT:
 * Input : 4
 * Output:
 * 1
 * 2 3
 * 4 5 6
 * 7 8 9 10
 */

#include <stdio.h>

int main() {
    int n, i, j, num = 1;

    printf("Enter number of rows: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d ", num);
            num++;   // counter keeps increasing across all rows
        }
        printf("\n");
    }

    return 0;
}
