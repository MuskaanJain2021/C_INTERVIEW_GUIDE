#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/**
 * @brief Inline function to check if a number is even.
 * 
 * This function uses bitwise operations to determine if a number is even.
 * 
 * @param num The integer to check.
 * @return true if the number is even, false otherwise.
 */
static inline bool is_even(int num) {
    return (num & 1) == 0;
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
char* DecToBin(unsigned int num);

int main() {
    long long num;  // Use long long to handle large input values
    
    printf("Enter an integer: ");
    // Validate input to ensure it is an integer
    if (scanf("%lld", &num) != 1) {
        printf("Invalid input. Please enter a valid integer.\n");
        return 1;
    }

    // Check if the number is within the range of signed 32-bit integer
    if (num < INT_MIN || num > INT_MAX) {
        printf("%lld is out of range for a 32-bit signed integer.\n", num);
        return 1;
    }

    // Cast to int after range check
    int signed_num = (int)num;
    
    // Check if the number is even or odd
    if (is_even(signed_num)) {
        printf("%d is even\n", signed_num);
    } else {
        printf("%d is odd\n", signed_num);
    }
    
    // Print the binary representation of the number
    printf("Binary representation of %d is %s\n", signed_num, DecToBin((unsigned int)signed_num));

    // If the number is negative, convert it to positive using two's complement technique
    if (signed_num < 0) {
        unsigned int positive_num = (unsigned int)(-signed_num);
        printf("Binary representation of the positive equivalent %u is %s\n", positive_num, DecToBin(positive_num));
    }
    
    return 0;
}

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
