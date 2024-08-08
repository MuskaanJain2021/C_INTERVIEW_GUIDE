#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Check if a number is a power of 2.
 * 
 * This function checks whether the given number `x` is a power of 2
 * using the expression `!(x & (x - 1)) && x`.
 * 
 * @param x The number to check.
 * @return true if `x` is a power of 2, false otherwise.
 */
bool isPowerOfTwo(unsigned int x) {
    return !(x & (x - 1)) && x;
}

int main() {
    unsigned int num;

    // Input from user
    printf("Enter a number: ");
    scanf("%u", &num);

    // Check if the number is a power of 2
    if (isPowerOfTwo(num)) {
        printf("%u is a power of 2.\n", num);
    } else {
        printf("%u is not a power of 2.\n", num);
    }

    return 0;
}
