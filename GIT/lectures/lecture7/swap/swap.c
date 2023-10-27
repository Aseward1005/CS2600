#include <stdio.h>

void swap(int *x, int *y);

int main()
{
    int a = 45, b = 35;
    printf("before swap\n");
    printf("a = %d, b = %d\n", a, b);

    swap(&a, &b);
    printf("after swap (pass by pointer value)\n");
    printf("a = %d, b = %d\n", a, b);

    return 0;
}

void swap(int *x, int *y)
{
    int z = *x;
    *x = *y;
    *y = z;
}