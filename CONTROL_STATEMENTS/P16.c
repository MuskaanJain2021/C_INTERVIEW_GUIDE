
/* Write a C program to print fibonacci series between 0 to 50.*/
#include <stdio.h>

void PrintFiboSeries(int limit)
{
    int a = 0, b = 1, c = 0;
    if (limit < 0)
    {
        printf("Limit should be non-negative \n");
        return;
    }
    printf("Fibonacci Series up to %d:\n", limit);

    if (a <= limit)
        printf("%d ", a);

    if (b <= limit)
        printf("%d ", b);

    while (1)
    {
        c = a + b;
        if (c > limit)  break;
        printf ("%d ",c);

        a=b;
        b=c;

    }
    printf("\n");
}





int main()
{
    int limit =  50;
    PrintFiboSeries(limit);
    return 0;

}