/* Program to Input 10 Numbers, Count Prime Numbers, Store Them in a Separate Array, and Display Them*/

#include <stdio.h>
#include <stdbool.h>

// Function prototypes
bool isPrime(int num);
void inputNumbers(int arr[], int size);
void findPrimes(const int input[], int size, int primes[], int *primeCount);
void displayArray(const int arr[], int size);

int main() {
    const int SIZE = 10;
    int numbers[SIZE];
    int primeNumbers[SIZE];
    int primeCount = 0;

    // Input numbers
    inputNumbers(numbers, SIZE);

    // Find prime numbers
    findPrimes(numbers, SIZE, primeNumbers, &primeCount);

    // Display prime numbers
    printf("Prime numbers are:\n");
    displayArray(primeNumbers, primeCount);
    printf("Total prime numbers count: %d\n", primeCount);

    return 0;
}

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// Function to input numbers
void inputNumbers(int arr[], int size) {
    printf("Enter %d numbers:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

// Function to find prime numbers and store them in an array
void findPrimes(const int input[], int size, int primes[], int *primeCount) {
    *primeCount = 0;
    for (int i = 0; i < size; i++) {
        if (isPrime(input[i])) {
            primes[*primeCount] = input[i];
            (*primeCount)++;
        }
    }
}

// Function to display elements of an array
void displayArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
