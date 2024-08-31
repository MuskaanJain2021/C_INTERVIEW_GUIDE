/*  Write a C program to find out the biggest number of  three variables using if-else ladder and terinary operator.*/


// #ifndef ELSEIFLADDER
// #define ELSEIFLADDER
// #include <stdio.h>

// int main() {
//     int num1, num2, num3;

//     printf("Enter three numbers: ");
//     scanf("%d %d %d", &num1, &num2, &num3);

//     if (num1 >= num2 && num1 >= num3)
//         printf("The largest number is: %d\n", num1);
//     else if (num2 >= num1 && num2 >= num3)
//         printf("The largest number is: %d\n", num2);
//     else
//         printf("The largest number is: %d\n", num3);

//     return 0;
// }

// #endif


#ifndef TERINARYOP
#define TERINARYOP
#include <stdio.h>

int main() {
    int num1, num2, num3;

    printf("Enter three numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    int largest = (num1 > num2) ? (num1 > num3 ? num1 : num3) : (num2 > num3 ? num2 : num3);

    printf("The largest number is: %d\n", largest);
    return 0;
}


#endif