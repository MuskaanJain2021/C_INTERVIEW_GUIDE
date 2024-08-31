/* Write a C program to find the given number is Perfect number or not?
       Note : Perfect number  means sum of it's divisers exept that num is equalent to the same  
                  number.

        Ex :  i/p num = 6.
                6 divisors  are  =  1,2,3, & 6.
                sum = 1+2+3
                sum  = 6.    So here  6 is perfect number.*/
#include <stdio.h>

// Function to check if a number is a perfect number
int isPerfectNumber(int num) {
    if (num < 2) {
        return 0;  // Numbers less than 2 cannot be perfect numbers
    }

    int sum = 1;  // Start with 1 as a divisor

    // Check all divisors from 2 to num/2
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            sum += i;
        }
    }

    return sum == num;
}

// Function to get user input
int getUserInput() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    return num;
}

// Function to print the result
void printResult(int num, int isPerfect) {
    if (isPerfect) {
        printf("%d is a Perfect number.\n", num);
    } else {
        printf("%d is not a Perfect number.\n", num);
    }
}

int main() {
    int num = getUserInput();
    int isPerfect = isPerfectNumber(num);
    printResult(num, isPerfect);

    return 0;
}


