/*  Original number: 10 (Binary: 00000000000000000000000000001010)
Number after swapping nibbles: 2684354560 (Binary: 10100000000000000000000000000000)
*/ 

#include <stdio.h>

// Function to extract the first nibble
unsigned int getFirstNibble(unsigned int num, unsigned int numBits) {
    return (num >> (numBits - 4)) & 0xF;
}

// Function to extract the last nibble
unsigned int getLastNibble(unsigned int num) {
    return num & 0xF;
}

// Function to clear the first and last nibbles
unsigned int clearFirstAndLastNibbles(unsigned int num, unsigned int numBits) {
    unsigned int mask = 0xF | (0xF << (numBits - 4));  // Mask to clear first and last nibble
    return num & ~mask;
}

// Function to swap the first and last nibbles
unsigned int swapNibbles(unsigned int num) {
    unsigned int numBits = sizeof(num) * 8;  // Number of bits in the integer

    unsigned int firstNibble = getFirstNibble(num, numBits);
    unsigned int lastNibble = getLastNibble(num);
    unsigned int middlePart = clearFirstAndLastNibbles(num, numBits);

    return (middlePart) | (firstNibble) | (lastNibble << (numBits - 4));
}

// Function to convert decimal to binary and store in an array
void decimalToBinary(unsigned int num, char* binaryStr, unsigned int numBits) {
    for (int i = numBits - 1; i >= 0; i--) {
        binaryStr[numBits - 1 - i] = (num & (1 << i)) ? '1' : '0';
    }
    binaryStr[numBits] = '\0';  // Null-terminate the string
}

int main() {
    unsigned int num = 10;
    unsigned int result = swapNibbles(num);

    unsigned int numBits = sizeof(num) * 8;  // Number of bits in the integer
    char binaryStrBefore[33], binaryStrAfter[33];  // 32 bits + 1 for null terminator

    decimalToBinary(num, binaryStrBefore, numBits);
    decimalToBinary(result, binaryStrAfter, numBits);

    printf("Original number: %u (Binary: %s)\n", num, binaryStrBefore);
    printf("Number after swapping nibbles: %u (Binary: %s)\n", result, binaryStrAfter);

    return 0;
}
