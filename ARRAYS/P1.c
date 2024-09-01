/*Program to Calculate the Sum of Even Numbers and the Product of Odd Numbers*/
#include <stdio.h>

#define ARRAY_SIZE 10

// Function prototypes
void inputNumbers(int arr[], int size);
void processNumbers(const int arr[], int size, int *evenSum, int *oddProduct);

int main(void) {
    int numbers[ARRAY_SIZE];
    int evenSum = 0, oddProduct = 1;

    // Input numbers from the user
    inputNumbers(numbers, ARRAY_SIZE);

    // Process numbers to find the sum of evens and product of odds
    processNumbers(numbers, ARRAY_SIZE, &evenSum, &oddProduct);

    // Display results
    printf("Sum of even numbers: %d\n", evenSum);
    printf("Product of odd numbers: %d\n", oddProduct);

    return 0;
}

// Function to input numbers into the array
void inputNumbers(int arr[], int size) {
    printf("Enter %d numbers:\n", size);
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to calculate the sum of even numbers and product of odd numbers
void processNumbers(const int arr[], int size, int *evenSum, int *oddProduct) {
    int hasOdd = 0;

    for(int i = 0; i < size; i++) {
        if(arr[i] % 2 == 0) {
            *evenSum += arr[i];
        } else {
            *oddProduct *= arr[i];
            hasOdd = 1;
        }
    }
    
    // Handle case where there are no odd numbers
    if (!hasOdd) {
        *oddProduct = 0;
    }
}
