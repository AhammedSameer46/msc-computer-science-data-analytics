/*
 * Program: Calculate Factorial using a User-Defined Function
 *
 * ALGORITHM:
 * 1. Define a function factorial(int n) that returns n!.
 * 2. Inside the function, use a loop to multiply numbers from
 *    1 to n.
 * 3. In main(), take input from the user, call the function,
 *    and print the returned result.
 *
 * EXPLANATION:
 * Putting the factorial logic inside its own function makes the
 * code reusable -- we can call factorial() as many times as we
 * like with different numbers without rewriting the loop.
 *
 * SAMPLE INPUT / OUTPUT:
 * Input : 6
 * Output: Factorial of 6 = 720
 */

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
