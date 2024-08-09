#include <stdio.h>
#include <stdint.h>

// Function to rotate bits to the right
uint32_t rotateRight(uint32_t num, unsigned int rotations) {
    return (num >> rotations) | (num << (32 - rotations));
}

// Function to rotate bits to the left
uint32_t rotateLeft(uint32_t num, unsigned int rotations) {
    return (num << rotations) | (num >> (32 - rotations));
}

int main() {
    uint32_t num;
    unsigned int rotations;
    char direction;

    // Input the number in hexadecimal format
    printf("Enter a 32-bit number in hexadecimal format: ");
    scanf("%x", &num);

    // Input the number of rotations and the direction
    printf("Enter the number of rotations: ");
    scanf("%u", &rotations);
    printf("Enter the direction of rotation (l for left, r for right): ");
    scanf(" %c", &direction);

    // Perform the rotation based on the direction
    if (direction == 'r' || direction == 'R') {
        num = rotateRight(num, rotations);
    } else if (direction == 'l' || direction == 'L') {
        num = rotateLeft(num, rotations);
    } else {
        printf("Invalid direction input.\n");
        return 1;
    }

    // Print the result in binary format
    printf("Result: %08X\n", num);
    return 0;
}
