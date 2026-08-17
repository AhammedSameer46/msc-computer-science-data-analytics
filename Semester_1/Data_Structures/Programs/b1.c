#include <stdio.h>

int main() {
    int n;

    printf("Enter number of scores: ");
    scanf("%d", &n);

    int scores[n];

    printf("Enter the scores:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &scores[i]);
    }

    int max = scores[0];

    printf("New leader appeared at position: 1 ");

    for (int i = 1; i < n; i++) {
        if (scores[i] > max) {
            max = scores[i];
            printf("%d ", i + 1);
        }
    }

    return 0;
}