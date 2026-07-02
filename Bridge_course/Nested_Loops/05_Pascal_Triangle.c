#include <stdio.h>

int main() {
    int n, i, j;
    long long value;

    printf("Enter number of rows: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        value = 1;   // first value in every row is always 1

        // Print leading spaces for a nicer triangular look (optional)
        for (j = 0; j < n - i - 1; j++) {
            printf("  ");
        }

        for (j = 0; j <= i; j++) {
            printf("%lld ", value);
            // update value to the next binomial coefficient in the row
            value = value * (i - j) / (j + 1);
        }
        printf("\n");
    }

    return 0;
}
