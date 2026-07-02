#include <stdio.h>

int main() {
    int n, i, first = 0, second = 1, next;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");

    for (i = 1; i <= n; i++) {
        if (i == 1) {
            printf("%d ", first);
            continue;
        }
        if (i == 2) {
            printf("%d ", second);
            continue;
        }
        next = first + second;   // new term = sum of previous two
        printf("%d ", next);
        first = second;          // shift values forward
        second = next;
    }
    printf("\n");

    return 0;
}
