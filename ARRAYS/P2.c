/*Program to Find the Largest and Smallest Number in an Unsorted Array*/
#include <stdio.h>

#define ARRAY_SIZE 10

// Function prototypes
void inputNumbers(int arr[], int size);
void findMinMax(const int arr[], int size, int *max, int *min);

int main(void) {
    int numbers[ARRAY_SIZE];
    int max, min;

    // Input numbers from the user
    inputNumbers(numbers, ARRAY_SIZE);

    // Find the maximum and minimum values
    findMinMax(numbers, ARRAY_SIZE, &max, &min);

    // Display results
    printf("Maximum number: %d\n", max);
    printf("Minimum number: %d\n", min);

    return 0;
}

// Function to input numbers into the array
void inputNumbers(int arr[], int size) {
    printf("Enter %d numbers:\n", size);
    for(int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to find the maximum and minimum number in the array
void findMinMax(const int arr[], int size, int *max, int *min) {
    *max = arr[0];
    *min = arr[0];

    for(int i = 1; i < size; i++) {
        if(arr[i] > *max) {
            *max = arr[i];
        }
        if(arr[i] < *min) {
            *min = arr[i];
        }
    }
}
