/*Remove duplicate elements from the array provided*/
#include <stdio.h>
#include <stdbool.h>

#define HASH_TABLE_SIZE 1000  // Adjust size based on expected range

// Simple hash function
size_t hash(int value) {
    return (size_t)(value % HASH_TABLE_SIZE);
}

// Function to initialize the hash table
void initHashTable(bool hashTable[]) {
    for (size_t i = 0; i < HASH_TABLE_SIZE; i++) {
        hashTable[i] = false;
    }
}

// Function to remove duplicates and count unique elements using a hash table
void removeDuplicates(int arr[], size_t num_elements, size_t *new_size) {
    if (arr == NULL || new_size == NULL) {
        fprintf(stderr, "Error: Null pointer passed to removeDuplicates function.\n");
        return;
    }

    bool hashTable[HASH_TABLE_SIZE];
    initHashTable(hashTable);  // Initialize hash table
    
    size_t index = 0;
    for (size_t i = 0; i < num_elements; i++) {
        if (i >= num_elements) {
            fprintf(stderr, "Error: Index out of bounds while processing the array.\n");
            return;
        }
        
        int value = arr[i];
        size_t hashValue = hash(value);

        if (!hashTable[hashValue]) {  // If value has not been seen
            hashTable[hashValue] = true;
            arr[index++] = value;  // Store unique value in the array
            printf("Unique value added: %d (Hash: %zu)\n", value, hashValue);
        } else {
            printf("Duplicate value skipped: %d (Hash: %zu)\n", value, hashValue);
        }
    }
    *new_size = index;  // Update the size to the number of unique elements
}

// Function to print the array
void printArray(const int arr[], size_t size) {
    if (arr == NULL) {
        fprintf(stderr, "Error: Null pointer passed to printArray function.\n");
        return;
    }
    
    printf("Array contents: ");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 2, 4, 5, 5};
    size_t num_elements = sizeof(arr) / sizeof(arr[0]);

    // Print the array before processing
    printf("Array before removing duplicates:\n");
    printArray(arr, num_elements);

    // Call the removeDuplicates function
    size_t new_size = num_elements;
    removeDuplicates(arr, num_elements, &new_size);

    // Print the array after removing duplicates
    printf("Array after removing duplicates:\n");
    printArray(arr, new_size);

    return 0;
}
