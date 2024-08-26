#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#define LIMIT 100

bool isPrime(int num)
{
    if (num <= 1)
        return false;
    if (num == 2)
        return true;
    if (num % 2 == 0)
        return false;

    for (int i = 3; i * i <= num; i += 2)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int count = 0, num = 2;
    while (count < LIMIT)
    {
        if (isPrime(num))
        {
            printf("%d ", num);
            count++;
        }
        ++num;
    }
}