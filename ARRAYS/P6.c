/*Write a C program to delete an element at desired position from an array.
  Original array: 10 20 30 40 50
  Enter the position to delete (0 to 4): 2
  Array after deletion: 10 20 40 50
*/

#include <stdio.h>

// Function to delete an element at a given position
int deleteElement(int arr[], int size, int position) {
    if (position < 0 || position >= size) {
        printf("Invalid position! Please enter a position between 0 and %d.\n", size - 1);
        return size;
    }

    for (int i = position; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--; // Decrease the size after deletion

    return size;
}

int main() {
    // Example array
    int arr[] = {10, 20, 30, 40, 50};

    // Calculate the size of the array using pointer arithmetic
    int *ptr1 = arr;
    int *ptr2 = arr + sizeof(arr) / sizeof(arr[0]);
    int size = ptr2 - ptr1;

    int position;

    // Print the original array
    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Input the position to delete
    printf("Enter the position to delete (0 to %d): ", size - 1);
    scanf("%d", &position);

    // Delete the element and get the new size
    size = deleteElement(arr, size, position);

    // Print the array after deletion
    printf("Array after deletion: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
