#include <stdio.h>
#include <limits.h>  // For UINT_MAX

unsigned int reverseBits(unsigned int num) {
    unsigned int reversed = 0;
    int bitCount = sizeof(num) * 8;  // Number of bits in the unsigned integer

    for (int i = 0; i < bitCount; i++) {
        reversed <<= 1;           // Shift reversed left to make room for the next bit
        if (num & 1)              // Check if the LSB of num is 1
            reversed |= 1;        // Set the LSB of reversed to 1 if the current bit of num is 1
        num >>= 1;                // Shift num right to process the next bit
    }

    return reversed;
}

int main() {
    int number;
    unsigned int unsignedNumber;

    printf("Enter an integer: ");
    scanf("%d", &number);

    // Handle negative numbers by converting to unsigned representation
    unsignedNumber = (unsigned int)number;

    printf("Original number: %d\n", number);
    printf("Binary representation: ");
    for (int i = sizeof(int) * 8 - 1; i >= 0; i--) {
        printf("%d", (unsignedNumber >> i) & 1);
    }
    printf("\n");

    printf("Reversed bits: %u\n", reverseBits(unsignedNumber));

    return 0;
}
