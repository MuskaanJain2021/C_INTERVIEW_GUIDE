/*Write a C program to print palindrome numbers between 1 to 1000.
       (palindrome numbers means the numbers which are equal to its reverse.                                    
         Ex : 11,22,33,44,.........999. )
*/
#include <stdio.h>

// Function to check if a number is a palindrome
int isPalindrome(int num) {
    int original = num, reversed = 0;
    
    // Reverse the number
    while (num > 0) {
        reversed = reversed * 10 + (num % 10);
        num /= 10;
    }
    
    // Check if original number is equal to its reverse
    return original == reversed;
}


int main() {
    printf("Palindrome numbers between 1 and 1000 are:\n");
    
    // Loop through numbers from 1 to 1000
    for (int i = 1; i <= 1000; i++) {
        if (isPalindrome(i)) {
            printf("%d ", i);
        }
    }
    
    printf("\n");
    return 0;
}
