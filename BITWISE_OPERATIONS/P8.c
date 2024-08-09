#include <stdio.h>

int main() {
    char ch;

    // Input a character
    printf("Enter a character: ");
    scanf(" %c", &ch);

    // Convert the character to its opposite case using XOR
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
        ch ^= ' '; // XOR with space (' ') to toggle case
    } else {
        printf("Not an alphabetic character.\n");
        return 1;
    }

    // Print the converted character
    printf("Converted character: %c\n", ch);

    return 0;
}
