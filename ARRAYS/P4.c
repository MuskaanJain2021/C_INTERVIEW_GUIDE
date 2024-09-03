/*Program to Find the Second Largest and Second Smallest Elements of an Unsorted Array Without Sorting
c*/
#include <stdio.h>
#include <limits.h>

// Function prototypes
void inputArray(int arr[], int size);
void findSecondLargestAndSmallest(const int arr[], int size, int *secondLargest, int *secondSmallest);

int main() {
    const int SIZE = 10;
    int arr[SIZE];
    int secondLargest, secondSmallest;

    // Input numbers
    inputArray(arr, SIZE);

    // Find second largest and second smallest
    findSecondLargestAndSmallest(arr, SIZE, &secondLargest, &secondSmallest);

    // Display results
    if (secondLargest == INT_MIN) {
        printf("There is no second largest element.\n");
    } else {
        printf("Second largest element: %d\n", secondLargest);
    }

    if (secondSmallest == INT_MAX) {
        printf("There is no second smallest element.\n");
    } else {
        printf("Second smallest element: %d\n", secondSmallest);
    }

    return 0;
}

// Function to input array elements
void inputArray(int arr[], int size) {
    printf("Enter %d numbers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to find the second largest and second smallest elements
void findSecondLargestAndSmallest(const int arr[], int size, int *secondLargest, int *secondSmallest) {
    int largest = INT_MIN, smallest = INT_MAX;
    *secondLargest = INT_MIN;
    *secondSmallest = INT_MAX;

    // Initial pass to find largest and smallest values
    for (int i = 0; i < size; i++) {
        if (arr[i] > largest) {
            *secondLargest = largest;
            largest = arr[i];
        } else if (arr[i] > *secondLargest && arr[i] < largest) {
            *secondLargest = arr[i];
        }

        if (arr[i] < smallest) {
            *secondSmallest = smallest;
            smallest = arr[i];
        } else if (arr[i] < *secondSmallest && arr[i] > smallest) {
            *secondSmallest = arr[i];
        }
    }
}
