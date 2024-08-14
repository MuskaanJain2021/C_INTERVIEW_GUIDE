#include <stdio.h>

// Macro to clear a bit at position N in an integer M
#define CLEAR_BIT(M, N) ((M) &= ~(1U << (N)))

// Function to print the binary representation of a 32-bit integer
void print_binary(int num) {
    for (int i = 31; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0) printf(" "); // Group by 4 bits for readability
    }
    printf("\n");
}

int main() {
    int num = 0xFFFFFFFF; // Example number: 4294967295 (binary: all 1s)
    int position = 15;    // We want to clear the bit at position 15

    printf("Before clearing bit at position %d: %d (binary: ", position, num);
    print_binary(num);
    
    CLEAR_BIT(num, position);
    
    printf("After clearing bit at position %d: %d (binary: ", position, num);
    print_binary(num);

    return 0;
}
