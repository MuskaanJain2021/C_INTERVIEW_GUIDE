#include <stdio.h>

int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;  // Extract the last digit and add it to sum
        num /= 10;        // Remove the last digit from num
    }
    return sum;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    // Handle negative numbers
    if (num < 0) {
        num = -num;  // Convert the number to positive for digit sum calculation
    }

    int result = sumOfDigits(num);
    printf("The sum of digits of %d is %d\n", num, result);

    return 0;
}
