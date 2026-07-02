#include <stdio.h>

// Function declaration (prototype)
long long factorial(int n);

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 0;
    }

    // Function call -- result is stored and then printed
    long long result = factorial(num);
    printf("Factorial of %d = %lld\n", num, result);

    return 0;
}

// Function definition: calculates n! using an iterative loop
long long factorial(int n) {
    long long fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;   // send the result back to the caller
}
