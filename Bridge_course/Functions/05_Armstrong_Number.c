#include <stdio.h>
#include <math.h>   // for pow()

// Function prototype
int isArmstrong(int n);

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (isArmstrong(num))
        printf("%d is an Armstrong number\n", num);
    else
        printf("%d is NOT an Armstrong number\n", num);

    return 0;
}

// Function definition: returns 1 if Armstrong number, else 0
int isArmstrong(int n) {
    int original = n, digitCount = 0, remainder;
    long long sum = 0;

    // Step 1: count number of digits
    int temp = n;
    if (temp == 0) digitCount = 1;
    while (temp != 0) {
        digitCount++;
        temp = temp / 10;
    }

    // Step 2: sum each digit raised to the power of digitCount
    temp = n;
    while (temp != 0) {
        remainder = temp % 10;
        sum += (long long) pow(remainder, digitCount);
        temp = temp / 10;
    }

    return (sum == original) ? 1 : 0;
}
