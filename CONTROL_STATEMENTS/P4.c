#include <stdio.h>

// Function to convert a lowercase character to uppercase
char toUpperCase(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return ch - 'a' + 'A';
    }
    return ch; // Return the character unchanged if it's not lowercase
}

// Function to convert an uppercase character to lowercase
char toLowerCase(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch - 'A' + 'a';
    }
    return ch; // Return the character unchanged if it's not uppercase
}

// Function to convert the case of a character
char ConvertCase(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return toUpperCase(ch);
    } else if (ch >= 'A' && ch <= 'Z') {
        return toLowerCase(ch);
    }
    return ch; // Return the character unchanged if it's not alphabetic
}

int main() {
    char ch;

    // Taking character input from the user
    printf("Enter a character: ");
    scanf("%c", &ch);

    // Convert and display the toggled character
    char convertedChar = ConvertCase(ch);
    printf("Converted character: %c\n", convertedChar);

    return 0;
}
