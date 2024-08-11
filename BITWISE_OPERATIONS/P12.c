#include <stdio.h>

// Function to create a mask with P bits set to 1
unsigned int createMask(unsigned int P) {
    return (1 << P) - 1;  // Creates a mask with P bits set to 1
}

// Function to extract P bits from position N
unsigned int extractBits(unsigned int M, unsigned int N, unsigned int P) {
    unsigned int mask = createMask(P);  // Create a mask with P bits set to 1
    return (M >> (N - 1)) & mask;  // Shift M to align desired bits and apply the mask
}

// Function to convert decimal to binary and store in an array
void decimalToBinary(unsigned int num, char* binaryStr, unsigned int numBits) {
    for (int i = numBits - 1; i >= 0; i--) {
        binaryStr[numBits - 1 - i] = (num & (1 << i)) ? '1' : '0';
    }
    binaryStr[numBits] = '\0';  // Null-terminate the string
}

int main() {
    unsigned int M = 0xABCDEF;  // Example number in hexadecimal
    unsigned int N = 12;  // Position to start extraction (1-based index)
    unsigned int P = 5;   // Number of bits to extract

    unsigned int extractedBits = extractBits(M, N, P);

    unsigned int numBits = sizeof(M) * 8;  // Number of bits in the integer
    char binaryStrBefore[33], binaryStrAfter[33];  // 32 bits + 1 for null terminator

    decimalToBinary(M, binaryStrBefore, numBits);
    decimalToBinary(extractedBits, binaryStrAfter, P);  // Only P bits for extracted value

    printf("Original number: 0x%X (Binary: %s)\n", M, binaryStrBefore);
    printf("Extracted %u bits from position %u: 0x%X (Binary: %s)\n", P, N, extractedBits, binaryStrAfter);

    return 0;
}
