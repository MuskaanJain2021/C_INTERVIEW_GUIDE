// Find the complement of a perticular bit. User has to take the position  number at runtime.

#include <stdio.h>
#include <stdlib.h>

// Function to convert a decimal number to a binary string
char* DecToBin(int num) {
    char* bin = (char*)malloc(33); // Allocate memory for 32 bits + null terminator
    bin[32] = '\0'; // Set the null terminator at the end of the string
    int idx;
    for (idx = 31; idx >= 0; idx--) {
        if (num & (1 << idx)) // Check if the bit is set
            bin[31 - idx] = '1'; // Set the corresponding index in the string to '1'
        else
            bin[31 - idx] = '0'; // Set the corresponding index in the string to '0'
    }
    return bin;
}

int main() {
    int num, position;
    
    // Input the number and bit position from the user
    printf("Enter an integer: ");
    scanf("%d", &num);
    
    printf("Enter the bit position (0-indexed): ");
    scanf("%d", &position);
    
    // Display the original number in binary
    char* originalBinary = DecToBin(num);
    printf("Integer before complementing its particular bit at position %d is: %d (%s)\n", position, num, originalBinary);
    
    // Toggle the bit at the given position
    num ^= (1 << position);
    
    // Display the modified number in binary
    char* modifiedBinary = DecToBin(num);
    printf("The number after toggling bit %d is: %d (%s)\n", position, num, modifiedBinary);
    
    // Free the allocated memory and assign pointers to NULL
    free(originalBinary);
    originalBinary = NULL;

    free(modifiedBinary);
    modifiedBinary = NULL;
    
    return 0;
}
