#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Check if a character is a digit.
 * 
 * This function checks if the provided character is a digit (0-9).
 * 
 * @param ch The character to check.
 * @return true if the character is a digit, false otherwise.
 */
bool is_digit(char ch) {
    return (ch >= '0' && ch <= '9');
}

/**
 * @brief Swap two integers using bitwise XOR.
 * 
 * This function swaps the values of two integers using bitwise XOR operations.
 * It includes a check to avoid swapping if both pointers point to the same memory location.
 * 
 * @param a Pointer to the first integer.
 * @param b Pointer to the second integer.
 */
void swap(int *a, int *b) {
    if (a != b) {
        *a = *a ^ *b;
        *b = *a ^ *b;
        *a = *a ^ *b;
    }
}

/**
 * @brief Print the binary representation of an integer.
 * 
 * This function converts an unsigned integer to its binary string representation and prints it.
 * 
 * @param num The integer to convert.
 */
void printBinary(int num) {
    unsigned int mask = 1 << (sizeof(int) * 8 - 1); // Start with the MSB
    for (int i = 0; i < sizeof(int) * 8; i++) {
        putchar((num & mask) ? '1' : '0');
        mask >>= 1; // Move to the next bit
    }
    putchar('\n');
}

/**
 * @brief Main function that combines integer input and swapping functionalities.
 * 
 * This function:
 * 1. Reads two integers from the user.
 * 2. Validates that the inputs are digits.
 * 3. Swaps the integers using bitwise XOR.
 * 4. Prints the binary representation of the integers before and after swapping.
 * 
 * @return 0 on successful execution, 1 on invalid input.
 */
int main() {
    int num1, num2;

    printf("Enter two integers: ");
    if (scanf("%d %d", &num1, &num2) != 2) {
        printf("Invalid input. Please enter two integers.\n");
        return 1;
    }

    // Print binary representations before swapping
    printf("Before swapping:\n");
    printf("num1 = %d, Binary: ", num1);
    printBinary(num1);
    printf("num2 = %d, Binary: ", num2);
    printBinary(num2);

    // Swap the numbers
    swap(&num1, &num2);

    // Print binary representations after swapping
    printf("After swapping:\n");
    printf("num1 = %d, Binary: ", num1);
    printBinary(num1);
    printf("num2 = %d, Binary: ", num2);
    printBinary(num2);

    return 0;
}
