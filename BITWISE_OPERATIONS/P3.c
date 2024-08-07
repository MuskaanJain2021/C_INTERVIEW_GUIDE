#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

/**
 * @brief Inline function to check if a number is negative.
 * 
 * This function uses bitwise operations to determine if a number is negative
 * by checking the most significant bit (MSB).
 * 
 * @param num The integer to check.
 * @return true if the number is negative, false otherwise.
 */
static inline bool is_negative(int num) {
    return (num & (1 << 31)) != 0;
}

/**
 * @brief Convert an unsigned integer to its binary string representation.
 * 
 * This function allocates memory for a string to hold the 32-bit binary
 * representation of an unsigned integer, including the null terminator.
 * 
 * @param num The unsigned integer to convert.
 * @return A pointer to the binary string representation.
 */
char* DecToBin(unsigned int num) {
    char* bin = (char*)malloc(33); // Allocate memory for 32 bits + null terminator
    if (bin == NULL) {
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

int main() {
    long long input;  // Use long long to handle larger values safely
    
    printf("Enter an integer: ");
    if (scanf("%lld", &input) != 1) {
        printf("Invalid input. Please enter a valid integer.\n");
        return 1;
    }

    // Check if the input is within the 32-bit signed integer range
    if (input < INT_MIN || input > INT_MAX) {
        printf("%lld is out of range for a 32-bit signed integer.\n", input);
        return 1;
    }

    // Cast to int after range check
    int num = (int)input;
    
    // Check if the number is negative or positive
    if (is_negative(num)) {
        printf("%d is negative\n", num);
    } else {
        printf("%d is positive\n", num);
    }

    // Print the binary representation of the number
    printf("Binary representation of %d is %s\n", num, DecToBin((unsigned int)num));

    // If the number is negative, convert it to positive using two's complement technique
    if (is_negative(num)) {
        unsigned int positive_num = (unsigned int)(-num);
        printf("Binary representation of the positive equivalent %u is %s\n", positive_num, DecToBin(positive_num));
    }
    
    return 0;
}
