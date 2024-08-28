#include <stdio.h>

// Function to calculate the power
double power(double base, int exp) {
    double result = 1.0;
    
    // If exponent is negative, we take the reciprocal of the base
    if (exp < 0) {
        base = 1.0 / base;
        exp = -exp;
    }

    // Multiply the base exponent times
    for (int i = 0; i < exp; i++) {
        result *= base;
    }

    return result;
}

int main() {
    double base;
    int exp;

    // Input the base and exponent
    printf("Enter the base: ");
    scanf("%lf", &base);
    printf("Enter the exponent: ");
    scanf("%d", &exp);

    // Calculate the power
    double result = power(base, exp);

    // Print the result
    printf("%.2lf raised to the power of %d is %.2lf\n", base, exp, result);

    return 0;
}
