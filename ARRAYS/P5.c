/*C program to reverse the elements of a given array
  Original array: 1 2 3 4 5 6 7
  Reversed array: 7 6 5 4 3 2 1
*/

#include <stdio.h>

// Function to reverse the array
void reverseArray(int arr[], int size) {
    if (size <= 1) {
        // No need to reverse if the array is empty or has one element
        return;
    }

    int start = 0;
    int end = size - 1;
    while (start < end) {
        // Swap elements at start and end
        arr[start] ^= arr[end];
        arr[end] ^= arr[start];
        arr[start] ^= arr[end];
        
        start++;
        end--;
    }
}

int main() {
    //array
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    // empty array check
    if (size == 0) {
        printf("Array is empty.\n");
        return 0;
    }

    // Print the original array
    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Reverse the array
    reverseArray(arr, size);

    // Print the reversed array
    printf("Reversed array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
