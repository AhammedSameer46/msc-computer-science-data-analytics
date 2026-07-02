#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter N (number of tables to print): ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {           // which table (1, 2, 3...)
        printf("Table of %d:\n", i);
        for (j = 1; j <= 10; j++) {      // multiplier from 1 to 10
            printf("%d x %d = %d\n", i, j, i * j);
        }
        printf("\n");   // blank line between tables
    }

    return 0;
}
