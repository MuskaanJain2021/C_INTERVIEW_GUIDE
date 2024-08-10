#include <stdio.h>

// Function to check if two integers are equal considering signedness
int areEqualConsideringSign(int x, int y) {
    return !((x ^ y) | ((x - y) >> (sizeof(int) * 8 - 1)));
}

int main() {
    int num1, num2;

    // Prompt user for input
    printf("Enter the first number: ");
    scanf("%d", &num1);
    printf("Enter the second number: ");
    scanf("%d", &num2);

    // Check if the numbers are equal considering signedness
    if (areEqualConsideringSign(num1, num2)) {
        printf("The numbers are equal considering signedness.\n");
    } else {
        printf("The numbers are not equal considering signedness.\n");
    }

    return 0;
}
