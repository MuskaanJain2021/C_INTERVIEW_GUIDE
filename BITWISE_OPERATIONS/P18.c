#include <stdio.h>
#include <stdint.h>

// Structure to represent the 48-bit data
typedef struct {
    uint32_t part1; // First 32 bits
    uint16_t part2; // Remaining 16 bits
} Data48;

// Function to extract 48 bits from a buffer and store them in a Data48 structure
Data48 store_48_bits(const char* buffer) {
    Data48 data = {0};

    // Combine the first 4 bytes into part1 (32 bits)
    data.part1 = ((uint32_t)buffer[0] << 24) |
                 ((uint32_t)buffer[1] << 16) |
                 ((uint32_t)buffer[2] <<  8) |
                 ((uint32_t)buffer[3]);

    // Combine the next 2 bytes into part2 (16 bits)
    data.part2 = ((uint16_t)buffer[4] << 8) |
                 ((uint16_t)buffer[5]);

    return data;
}

int main() {
    // Example buffer with 48 bits (6 bytes)
    char buffer[6] = {0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC};

    // Store the 48 bits into two integer variables
    Data48 data = store_48_bits(buffer);

    // Output the results
    printf("Part 1 (32 bits): 0x%08X\n", data.part1);
    printf("Part 2 (16 bits): 0x%04X\n", data.part2);

    return 0;
}
