/*Inserting an Element at a Specific Position in Array*/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <errno.h>

#define INITIAL_CAPACITY 4
#define GROWTH_FACTOR 2
#define AUTO_INSERT 0  // Set to 1 for auto-insertion, 0 for user input
#define DEBUG 1

typedef struct {
    int* data;       // Pointer to the array data
    size_t size;     // Current number of elements in the array
    size_t capacity; // Current capacity of the array
} DynamicArray;

typedef enum {
    DYNARRAY_SUCCESS,
    DYNARRAY_INVALID_CAPACITY,
    DYNARRAY_MEMORY_ERROR,
    DYNARRAY_INDEX_OUT_OF_BOUNDS,
    DYNARRAY_INVALID_INPUT
} DynArrayResult;

// Macro to print debug information
#if DEBUG
    #define PRINT_DEBUG(...) debugPrintf(__VA_ARGS__)
#else
    #define PRINT_DEBUG(...)
#endif

// Variadic function to handle debug prints
void debugPrintf(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

// Function to initialize the dynamic array with user-defined or automated values
DynArrayResult dynarray_init(DynamicArray* arr, size_t initial_capacity) {
    if (initial_capacity == 0) return DYNARRAY_INVALID_CAPACITY;

    arr->data = calloc(initial_capacity, sizeof(int));  // Initialize all elements to 0
    if (arr->data == NULL) return DYNARRAY_MEMORY_ERROR;

    arr->size = 0;
    arr->capacity = initial_capacity;
    PRINT_DEBUG("Initialized array with capacity %zu\n", initial_capacity);
    return DYNARRAY_SUCCESS;
}

// Function to resize the array
DynArrayResult dynarray_resize(DynamicArray* arr) {
    size_t new_capacity = arr->capacity * GROWTH_FACTOR;
    PRINT_DEBUG("Resizing array from %zu to %zu\n", arr->capacity, new_capacity);
    int* new_data = realloc(arr->data, new_capacity * sizeof(int));
    if (new_data == NULL) return DYNARRAY_MEMORY_ERROR;

    arr->data = new_data;
    arr->capacity = new_capacity;
    return DYNARRAY_SUCCESS;
}

// Function to insert an element at a specific position in the dynamic array
DynArrayResult dynarray_insert(DynamicArray* arr, size_t index, int value) {
    // Resize the array if necessary
    if (index >= arr->capacity) {
        DynArrayResult result = dynarray_resize(arr);
        if (result != DYNARRAY_SUCCESS) return result;
    }

    // If index is greater than the current size, fill the gap with zeros
    if (index > arr->size) {
        PRINT_DEBUG("Filling gap from size %zu to index %zu with zeros\n", arr->size, index);
        for (size_t i = arr->size; i < index; i++) {
            arr->data[i] = 0;  // Fill new positions with zeros
        }
        arr->size = index;  // Update size to the new index
    }

    // If the array is not full, resize it
    if (arr->size >= arr->capacity) {
        DynArrayResult result = dynarray_resize(arr);
        if (result != DYNARRAY_SUCCESS) return result;
    }

    // Shift elements to the right to make space for the new element
    PRINT_DEBUG("Shifting elements to the right to insert at index %zu\n", index);
    for (size_t i = arr->size; i > index; i--) {
        arr->data[i] = arr->data[i - 1];
    }

    // Insert the new element
    arr->data[index] = value;
    arr->size++;
    PRINT_DEBUG("Inserted value %d at index %zu\n", value, index);

    return DYNARRAY_SUCCESS;
}

// Function to free the dynamic array and set pointer to NULL
void dynarray_free(DynamicArray* arr) {
    PRINT_DEBUG("Freeing array memory\n");
    free(arr->data);
    arr->data = NULL;
    arr->size = arr->capacity = 0;
}

// Function to print the elements of the dynamic array with a given message
void printArray(DynamicArray* arr, const char* message) {
    printf("%s\n", message);
    for (size_t i = 0; i < arr->size; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

// Function to get user input with validation
DynArrayResult getUserInput(int* value, int autoInsert) {
    if (autoInsert) {
        *value = rand() % 100;  // Auto-generate a random value
        PRINT_DEBUG("Auto-generated value %d\n", *value);
    } else {
        printf("Enter the element to be inserted: ");
        if (scanf("%d", value) != 1) return DYNARRAY_INVALID_INPUT;
    }
    return DYNARRAY_SUCCESS;
}

// Main function
int main() {
    DynamicArray arr;
    DynArrayResult result = dynarray_init(&arr, INITIAL_CAPACITY);
    if (result != DYNARRAY_SUCCESS) {
        fprintf(stderr, "Failed to initialize array: %d\n", result);
        return 1;
    }

    // Initialize the array with user-defined values
    size_t initial_elements;
    printf("Enter the number of elements to initialize: ");
    if (scanf("%zu", &initial_elements) != 1) {
        fprintf(stderr, "Invalid input for number of elements.\n");
        dynarray_free(&arr);
        return 1;
    }

    for (size_t i = 0; i < initial_elements; i++) {
        int value;
        printf("Enter value for element %zu: ", i);
        if (scanf("%d", &value) != 1) {
            fprintf(stderr, "Invalid input for element value.\n");
            dynarray_free(&arr);
            return 1;
        }
        result = dynarray_insert(&arr, i, value);
        if (result != DYNARRAY_SUCCESS) {
            fprintf(stderr, "Failed to insert element: %d\n", result);
            dynarray_free(&arr);
            return 1;
        }
    }

    // Print the array before insertion
    printArray(&arr, "Array contents before insertion:");

    // Insert an element at a specific position
    size_t position;
    int valueToInsert;
    printf("Enter the position where the element is to be inserted: ");
    if (scanf("%zu", &position) != 1) {
        fprintf(stderr, "Invalid input for position.\n");
        dynarray_free(&arr);
        return 1;
    }

    result = getUserInput(&valueToInsert, AUTO_INSERT);
    if (result != DYNARRAY_SUCCESS) {
        fprintf(stderr, "Failed to get user input: %d\n", result);
        dynarray_free(&arr);
        return 1;
    }

    result = dynarray_insert(&arr, position, valueToInsert);
    if (result != DYNARRAY_SUCCESS) {
        fprintf(stderr, "Failed to insert element: %d\n", result);
        dynarray_free(&arr);
        return 1;
    }

    // Print the array after insertion
    printArray(&arr, "Array contents after insertion:");

    // Free the allocated memory
    dynarray_free(&arr);
    return 0;
}
