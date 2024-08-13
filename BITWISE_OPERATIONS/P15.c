/*Write a program to print float binary formation using char *ptr.
Enter a float number: 11.2
Binary representation of 11.200000 is: 01000001 00110011 00110011 00110011*/
#include <stdio.h>

void printBinary(float num) {
    unsigned int *binaryPtr = (unsigned int *)&num;  // Point to the float as an unsigned int
    unsigned int mask = 1 << 31;  // Start with the most significant bit

    for (int i = 0; i < 32; i++) {
        printf("%d", (*binaryPtr & mask) ? 1 : 0);
        mask >>= 1;
        
//    Add a space after every 8 bits for better readability
        if ((i + 1) % 8 == 0) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    float num;
    printf("Enter a float number: ");
    scanf("%f", &num);

    printf("Binary representation of %f is: ", num);
    printBinary(num);

    return 0;
}
