#include <stdio.h>

int cube(int num) {
    return num * num * num;
}

int main() {
    int num, sum, temp, remainder;

    for (num = 1; num <= 500; num++) {
        temp = num;
        sum = 0;

        while (temp != 0) {
            remainder = temp % 10;
            sum += cube(remainder);
            temp /= 10;
        }

        if (sum == num) {
            printf("%d ", num);
        }
    }
    printf("\n");
    return 0;
}
