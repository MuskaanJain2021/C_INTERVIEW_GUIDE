#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Converts a decimal number to its binary string representation.
 * 
 * This function allocates memory for a 32-bit binary string representation
 * of a given decimal number. It converts the decimal number to binary and
 * stores the result in the allocated memory.
 * 
 * @param num The decimal number to be converted.
 * @return A pointer to a string containing the binary representation of the number.
 *         The caller is responsible for freeing the allocated memory.
 */
char* DecToBin(unsigned int num) {
    // Allocate memory for 32 bits + null terminator
    char* bin = (char*)malloc(33);
    if (bin == NULL) {
        // Handle memory allocation failure
        printf("Memory allocation failed.\n");
        exit(1);
    }
    bin[32] = '\0'; // Set the null terminator at the end of the string

    // Loop through each bit and set the corresponding character in the string
    for (int idx = 31; idx >= 0; idx--) {
        bin[31 - idx] = (num & (1 << idx)) ? '1' : '0';
    }
    
    return bin;
}

/**
 * @brief Frees the allocated memory for a binary string and sets the pointer to NULL.
 * 
 * This function takes a pointer to the pointer of the binary string, frees the allocated
 * memory, and then sets the pointer to NULL to avoid dangling pointers.
 * 
 * @param bin Pointer to the binary string to be freed.
 */
void FreeBinString(char** bin) {
    free(*bin);
    *bin = NULL; // Assign the pointer to NULL to avoid dangling pointers
}

/**
 * @brief Main function to test the DecToBin and FreeBinString functions.
 * 
 * The main function prompts the user to enter a decimal number, converts the number
 * to binary using the DecToBin function, checks if the number is divisible by 8 using
 * bitwise operations, and then frees the allocated memory for the binary string.
 * 
 * @return int Exit status of the program.
 */
int main() {
    unsigned int num;
    // Prompt the user to enter a number
    printf("Enter a number: ");
    scanf("%u", &num);

    // Convert the number to binary
    char* binaryString = DecToBin(num);
    // Print the binary representation
    printf("Binary representation: %s\n", binaryString);

    // Check if the number is divisible by 8 using bitwise operation
    if ((num & 7) == 0) {
        printf("%u is divisible by 8.\n", num);
    } else {
        printf("%u is not divisible by 8.\n", num);
    }

    // Free the allocated memory for the binary string
    FreeBinString(&binaryString);

    return 0;
}
