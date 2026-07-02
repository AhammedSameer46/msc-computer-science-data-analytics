#include <stdio.h>

int main() {
    int n, i, sum = 0;

    printf("Enter N: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        sum = sum + i;   // add current number to the running total
    }

    printf("Sum of first %d natural numbers = %d\n", n, sum);

    return 0;
}
