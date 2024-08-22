#include <stdio.h>

int reverseDigits(int num) {
    int reversed = 0;
    while (num != 0) {
        reversed = reversed * 10 + num % 10; // Add the last digit to reversed number
        num /= 10; // Remove the last digit from the number
    }
    return reversed;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    // Handle negative numbers
    int isNegative = 0;
    if (num < 0) {
        isNegative = 1;
        num = -num; // Convert the number to positive for reversing
    }

    int reversed = reverseDigits(num);

    // Restore the sign for negative numbers
    if (isNegative) {
        reversed = -reversed;
    }

    printf("The reversed number is %d\n", reversed);

    return 0;
}
