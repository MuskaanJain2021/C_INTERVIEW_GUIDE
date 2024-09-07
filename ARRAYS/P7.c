/*Inserting an Element at a Specific Position in Array*/
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 4

// Function to resize the array
int* resizeArray(int* array, size_t* capacity) {
    *capacity *= 2;  // Double the capacity
    int* newArray = realloc(array, (*capacity) * sizeof(int));
    if (newArray == NULL) {
        fprintf(stderr, "Error: Memory allocation failed during resize.\n");
        free(array);  // Free the old array if reallocation fails
        exit(EXIT_FAILURE);
    }
    return newArray;
}

// Function to initialize the dynamic array
int* initializeArray(size_t* capacity) {
    int* array = calloc(*capacity, sizeof(int));  // Initialize all elements to 0
    if (array == NULL) {
        fprintf(stderr, "Error: Memory allocation failed during initialization.\n");
        exit(EXIT_FAILURE);
    }
    return array;
}

// Function to free the dynamic array and set pointer to NULL
void freeArray(int** array) {
    if (*array != NULL) {
        free(*array);
        *array = NULL;  // Avoid dangling pointer
    }
}

// Function to insert an element at a specific position
void insertElement(int** array, size_t* size, size_t* capacity, int element, size_t position) {
    if (*size >= *capacity) {
        *array = resizeArray(*array, capacity);
    }
    if (position > *size) {
        fprintf(stderr, "Error: Position out of bounds.\n");
        return;
    }
    // Shift elements to the right to make space for the new element
    for (size_t i = *size; i > position; i--) {
        (*array)[i] = (*array)[i - 1];
    }
    (*array)[position] = element;
    (*size)++;
}

// Function to print the array
void printArray(int* array, size_t size, const char* message) {
    printf("%s\n", message);
    for (size_t i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    size_t capacity = INITIAL_CAPACITY;
    size_t size = 0;
    int* array = initializeArray(&capacity);

    // Add initial elements
    for (int i = 0; i < 10; i++) {
        if (size >= capacity) {
            array = resizeArray(array, &capacity);
        }
        array[size++] = i;
    }

    // Print the array before inserting
    printArray(array, size, "Array contents before insertion:");

    // Insert an element at a specific position
    int elementToInsert = 99;
    size_t positionToInsert = 5;  // Example position
    printf("Inserting %d at position %zu...\n", elementToInsert, positionToInsert);
    insertElement(&array, &size, &capacity, elementToInsert, positionToInsert);

    // Print the array after insertion
    printArray(array, size, "Array contents after insertion:");

    // Free the allocated memory
    freeArray(&array);

    return 0;
}
