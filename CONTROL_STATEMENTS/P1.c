#include <stdio.h>

// Function to calculate factorial recursively
long long int FactorialCreate(int num) {
    if (num == 0)
        return 1;
    return num * FactorialCreate(num - 1);
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    // Handle negative inputs
    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        long long int fact = FactorialCreate(num);
        printf("Factorial of %d is %lld\n", num, fact);
    }

    return 0;
}
