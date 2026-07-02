#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter number of rows: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {        // controls the row number
        for (j = 1; j <= i; j++) {    // prints i stars in row i
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}
