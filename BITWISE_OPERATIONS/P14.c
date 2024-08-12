#include <stdio.h>
#include <limits.h>

// Function to swap the first and last nibbles of a given integer
unsigned int swapNibbles(unsigned int num, int bitSize) {
    int nibbleSize = 4;  // Size of a nibble in bits
    int numNibbles = bitSize / nibbleSize;

    // Mask to extract a nibble
    unsigned int nibbleMask = (1U << nibbleSize) - 1;

    // Extract the first and last nibbles
    unsigned int firstNibble = (num >> (bitSize - nibbleSize)) & nibbleMask;
    unsigned int lastNibble = num & nibbleMask;

    // Clear the first and last nibbles in the original number
    unsigned int clearedNum = (num & ~((nibbleMask << (bitSize - nibbleSize)) | nibbleMask));

    // Place the last nibble in the first nibble position
    clearedNum |= (lastNibble << (bitSize - nibbleSize));

    // Place the first nibble in the last nibble position
    clearedNum |= firstNibble;

    return clearedNum;
}

// Function to print binary representation
void printBinary(unsigned int num, int bitSize) {
    for (int i = bitSize - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int main() {
    unsigned int num;
    
    // Determine the bit size (e.g., 32 for unsigned int)
    int bitSize = sizeof(num) * CHAR_BIT;

    // Input the number
    printf("Enter the number: ");
    scanf("%u", &num);

    // Display binary representation before swap
    printf("Binary representation before swap: ");
    printBinary(num, bitSize);

    // Swap the nibbles
    unsigned int result = swapNibbles(num, bitSize);

    // Display binary representation after swap
    printf("Binary representation after swap:  ");
    printBinary(result, bitSize);

    // Display the result in decimal
    printf("The resulting number is: %u\n", result);

    return 0;
}
