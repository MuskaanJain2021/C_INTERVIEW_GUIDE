/*Write a C program to find the given number is power of 2 or not.*/
#include <stdio.h>
#include <stdbool.h>


bool isPowerOfTwo(unsigned int n) {
    
    return (n > 0) && ((n & (n - 1)) == 0);
}

int main() {
    unsigned int num;
    int result;

    printf("Enter a positive integer: ");
    
    // Ensure valid input
    if (scanf("%u", &num) != 1) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    // Check if the number is a power of 2
    if (isPowerOfTwo(num)) {
        printf("%u is a power of 2.\n", num);
    } else {
        printf("%u is not a power of 2.\n", num);
    }

    return 0;
}
