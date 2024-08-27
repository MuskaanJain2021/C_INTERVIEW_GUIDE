#include <stdio.h>
#include <limits.h>

// Define a structure to store display functions for different formats
typedef struct {
    const char *formatName;
    void (*displayFormat)(int num);
} Format;

// Function to display binary representation
void displayBinary(int num) {
    for (int i = sizeof(num) * CHAR_BIT - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

// Function to display decimal representation
void displayDecimal(int num) {
    printf("%d\n", num);
}

// Function to display octal representation
void displayOctal(int num) {
    printf("%o\n", num);
}

// Function to display hexadecimal representation
void displayHexadecimal(int num) {
    printf("%X\n", num);
}

// Function to calculate and display the complement in all formats
void displayComplement(int num, Format formats[], int formatCount) {
    int complement = ~num;

    printf("\nOriginal Number: %d\n", num);
    printf("Complement: %d\n", complement);

    for (int i = 0; i < formatCount; i++) {
        printf("\n%s Representation:\n", formats[i].formatName);
        printf("Original: ");
        formats[i].displayFormat(num);
        printf("Complement: ");
        formats[i].displayFormat(complement);
    }
}

int main(void) {
    int num;

    // Array of structures holding different display formats
    Format formats[] = {
        {"Binary", displayBinary},
        {"Decimal", displayDecimal},
        {"Octal", displayOctal},
        {"Hexadecimal", displayHexadecimal}
    };

    int formatCount = sizeof(formats) / sizeof(formats[0]);

    // User input
    printf("Enter an integer: ");
    scanf("%d", &num);

    // Display the complement and its representation in different formats
    displayComplement(num, formats, formatCount);

    return 0;
}
