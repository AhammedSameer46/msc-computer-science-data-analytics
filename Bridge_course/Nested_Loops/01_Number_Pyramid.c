#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter number of rows: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {          // outer loop -> controls row
        for (j = 1; j <= i; j++) {      // inner loop -> controls columns
            printf("%d ", j);
        }
        printf("\n");   // move to next row after inner loop finishes
    }

    return 0;
}
