#include <stdio.h>
#include <stdlib.h>

// Function to convert a decimal number to binary and store it in a string
char* DecToBin(unsigned int num) {
    char* bin = (char*)malloc(33); // Allocate memory for 32 bits + null terminator
    if (bin == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    bin[32] = '\0'; // Set the null terminator at the end of the string

    for (int idx = 31; idx >= 0; idx--) {
        bin[31 - idx] = (num & (1 << idx)) ? '1' : '0';
    }

    return bin;
}

// Function to reverse the bits of an unsigned integer
unsigned int reverseBits(unsigned int n) {
    unsigned int reversed = 0;
    int bitCount = sizeof(n) * 8; // Number of bits in the integer

    for (int i = 0; i < bitCount; i++) {
        reversed <<= 1;       // Shift reversed left to make room for the next bit
        reversed |= (n & 1);  // Add the least significant bit of n to reversed
        n >>= 1;              // Shift n right to process the next bit
    }
    return reversed;
}

int main() {
    int choice;
    printf("Enter 1 for signed number or 2 for unsigned number: ");
    scanf("%d", &choice);

    if (choice == 1) {
        // Handle signed number
        int n;
        printf("Enter a signed number: ");
        scanf("%d", &n);

        unsigned int unsigned_n = (unsigned int)n;

        // Print the original number and its binary representation
        char* originalBinary = DecToBin(unsigned_n);
        printf("Original signed number: %d\n", n);
        printf("Binary before reversal: %s\n", originalBinary);

        // Reverse the bits and print the reversed binary number
        unsigned int reversed = reverseBits(unsigned_n);
        char* reversedBinary = DecToBin(reversed);
        printf("Reversed number: %u\n", reversed);
        printf("Binary after reversal: %s\n", reversedBinary);

        // Free allocated memory
        free(originalBinary);
        originalBinary = NULL;
        free(reversedBinary);
        reversedBinary = NULL;

    } else if (choice == 2) {
        // Handle unsigned number
        unsigned int n;
        printf("Enter an unsigned number: ");
        scanf("%u", &n);

        // Print the original number and its binary representation
        char* originalBinary = DecToBin(n);
        printf("Original unsigned number: %u\n", n);
        printf("Binary before reversal: %s\n", originalBinary);

        // Reverse the bits and print the reversed binary number
        unsigned int reversed = reverseBits(n);
        char* reversedBinary = DecToBin(reversed);
        printf("Reversed number: %u\n", reversed);
        printf("Binary after reversal: %s\n", reversedBinary);

        // Free allocated memory
        free(originalBinary);
        originalBinary = NULL;
        free(reversedBinary);
        reversedBinary = NULL;

    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}
