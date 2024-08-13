#include <stdio.h>

// Function to convert a number to its binary representation
void printBinary(unsigned int num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 8 == 0 && i != 0) {
            printf(" ");
        }
    }
}

// Function to swap adjacent bytes of a 32-bit number
unsigned int swapAdjacentBytes(unsigned int num) {
    unsigned char bytes[4];
    
    // Extract bytes into the array
    bytes[0] = (num >> 24) & 0xFF;  // Most significant byte
    bytes[1] = (num >> 16) & 0xFF;  // Second byte
    bytes[2] = (num >> 8) & 0xFF;   // Third byte
    bytes[3] = num & 0xFF;          // Least significant byte

    // Swap adjacent bytes
    return (bytes[2] << 24) | (bytes[3] << 16) | (bytes[0] << 8) | bytes[1];
}

int main() {
    unsigned int num;
    printf("Enter a 4-byte (32-bit) hexadecimal number (e.g., 0x12345678): ");
    scanf("%x", &num);  // %x is used to read a hexadecimal number

    unsigned int swapped_num = swapAdjacentBytes(num);
    
    printf("Original number: 0x%08X\n", num);
    printf("Binary representation (original): ");
    printBinary(num);
    printf("\n");

    printf("After swapping adjacent bytes: 0x%08X\n", swapped_num);
    printf("Binary representation (swapped): ");
    printBinary(swapped_num);
    printf("\n");

    return 0;
}
