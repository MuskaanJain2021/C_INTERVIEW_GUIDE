#include <stdio.h>

// Function to convert a decimal number to binary and store it in a string
void decimalToBinary(unsigned int num, char *binaryStr) {
    int index = 31;  // Assuming a 32-bit integer
    for (int i = 0; i < 32; i++) {
        binaryStr[index--] = (num & 1) ? '1' : '0';
        num >>= 1;
    }
    binaryStr[32] = '\0';  // Null-terminate the string
}

// Function to delete n bits from a given position p in a number num
unsigned int deleteBits(unsigned int num, int p, int n) {
    // Validate inputs
    if (p < n || n < 0 || p < 0) {
        printf("Invalid position or number of bits\n");
        return num;
    }

    // Create masks to preserve lower bits and higher bits
    unsigned int lowerBitsMask = (1U << (p - n)) - 1;
    unsigned int higherBitsShifted = num >> p;

    // Combine the preserved lower bits and shifted higher bits
    unsigned int result = (num & lowerBitsMask) | (higherBitsShifted << (p - n));
    
    return result;
}

int main() {
    unsigned int num;
    int position, bitsToDelete;
    char binaryBefore[33], binaryAfter[33];

    // Input the number
    printf("Enter the number: ");
    scanf("%u", &num);

    // Input the position from where to delete the bits (1-based indexing)
    printf("Enter the position (from LSB) to start deleting bits: ");
    scanf("%d", &position);

    // Input the number of bits to delete
    printf("Enter the number of bits to delete: ");
    scanf("%d", &bitsToDelete);

    // Convert the number to binary before deletion
    decimalToBinary(num, binaryBefore);

    // Call the deleteBits function
    unsigned int result = deleteBits(num, position, bitsToDelete);

    // Convert the result to binary after deletion
    decimalToBinary(result, binaryAfter);

    // Display the results
    printf("Binary before deleting bits:  %s\n", binaryBefore);
    printf("Binary after deleting bits:   %s\n", binaryAfter);
    printf("The resulting number is:      %u\n", result);

    return 0;
}
