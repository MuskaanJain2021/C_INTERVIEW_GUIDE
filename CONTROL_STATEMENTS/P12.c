#include <stdio.h>
#include <limits.h>

// Function to print the binary representation of a number
void printBinary(int n) {
    for (int i = sizeof(int) * CHAR_BIT - 1; i >= 0; i--) {
        printf("%d", (n >> i) & 1);
    }
    printf("\n");
}

int main() {
    int num, twosComplement;

    // Input the number
    printf("Enter a number: ");
    scanf("%d", &num);

    // Calculate 2's complement
    twosComplement = ~num + 1;

    // Print the original number in different formats
    printf("\nOriginal Number:\n");
    printf("Binary: ");
    printBinary(num);
    printf("Decimal: %d\n", num);
    printf("Octal: %o\n", num);
    printf("Hexadecimal: %X\n", num);

    // Print the 2's complement number in different formats
    printf("\n2's Complement of %d:\n", num);
    printf("Binary: ");
    printBinary(twosComplement);
    printf("Decimal: %d\n", twosComplement);
    printf("Octal: %o\n", twosComplement);
    printf("Hexadecimal: %X\n", twosComplement);

    // Verify the formula: 2's complement of (x) = -x
    printf("\nVerification: -(%d) = %d\n", num, -num);
    if (twosComplement == -num) {
        printf("Formula is satisfied.\n");
    } else {
        printf("Formula is not satisfied.\n");
    }

    return 0;
}
