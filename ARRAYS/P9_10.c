/*9.Find and Count Duplicates[Given an array of integers, identify duplicate elements and their frequencies.]
  10. Print Unique Numbers[From the same array, print elements that appear exactly once (unique elements).
]
*/

#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 100

typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

Node* hashTable[TABLE_SIZE];

// Hash function to calculate index
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Insert key-value pair into the hashtable
void insert(int key) {
    int hashIndex = hashFunction(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = 1;  // Initialize frequency as 1
    newNode->next = NULL;

    // Collision handling using chaining
    if (hashTable[hashIndex] == NULL) {
        hashTable[hashIndex] = newNode;
    } else {
        Node* temp = hashTable[hashIndex];
        while (temp != NULL) {
            if (temp->key == key) {
                temp->value++;  // Increment frequency
                free(newNode);  // Free the new node, since key already exists
                return;
            }
            temp = temp->next;
        }
        newNode->next = hashTable[hashIndex];
        hashTable[hashIndex] = newNode;
    }
}

// Search for a key in the hashtable
Node* search(int key) {
    int hashIndex = hashFunction(key);
    Node* temp = hashTable[hashIndex];
    
    while (temp != NULL) {
        if (temp->key == key) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Print duplicate elements
void printDuplicates() {
    printf("Duplicate elements:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* temp = hashTable[i];
        while (temp != NULL) {
            if (temp->value > 1) {
                printf("%d occurs %d times\n", temp->key, temp->value);
            }
            temp = temp->next;
        }
    }
}

// Print unique elements
void printUnique() {
    printf("Unique elements:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* temp = hashTable[i];
        while (temp != NULL) {
            if (temp->value == 1) {
                printf("%d ", temp->key);
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

int main() {
    // Initialize hash table to NULL
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }

    int arr[] = {2, 3, 4, 3, 5, 2, 6, 7, 8, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Insert elements into the hash table
    for (int i = 0; i < size; i++) {
        insert(arr[i]);
    }

    // Print duplicates
    printDuplicates();

    // Print unique elements
    printUnique();

    return 0;
}
