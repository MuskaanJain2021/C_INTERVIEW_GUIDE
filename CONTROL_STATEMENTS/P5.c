#include <stdio.h>

// Function to print multiplication tables from `start` to `end`
void printMultiplicationTables(int start, int end) {
    // Iterate over the range of numbers for which we want to print the tables
    for (int i = 1; i <= (end - start + 1) * 10; i++) {
        // Determine the current number for which the multiplication table is being printed
        int number = start + (i - 1) / 10;
        
        // Determine the current multiplier (1 through 10)
        int multiplier = (i - 1) % 10 + 1;

        // Print the current multiplication result
        printf("%d x %d = %d\n", number, multiplier, number * multiplier);

        // Print a newline after completing each table (after every 10 multiplications)
        if (multiplier == 10) {
            printf("\n");
        }
    }
}

// Main function where execution starts
int main() {
    // Call the function to print tables from 10 to 20
    printMultiplicationTables(10, 20);
    return 0;
}
