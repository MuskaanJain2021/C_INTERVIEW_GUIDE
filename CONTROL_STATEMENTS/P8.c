#include <stdio.h>

void printBinary(int num) {
    // Check if the number is negative
    if (num < 0) {
        printf("-");  // Indicate it's a negative number
        num = ~(-num) + 1;  // Convert to two's complement for proper representation
    }

    unsigned int mask = 1 << (sizeof(int) * 8 - 1);  // Start with the most significant bit

    for (unsigned int i = 0; i < sizeof(int) * 8; i++) {
        // Check if the current bit is 1 or 0 and print accordingly
        if (num & mask) {
            printf("1");
        } else {
            printf("0");
        }
        mask >>= 1;  // Shift the mask right to check the next bit
    }

    printf("\n");
}

int main() {
    int number;

    printf("Enter an integer: ");
    scanf("%d", &number);

    printf("Binary representation: ");
    printBinary(number);

    return 0;
}
