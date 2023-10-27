#include<stdio.h>

typedef int number;

int main() 
{
    number c;
    printf("Enter a value : ");

    c = getchar();
    printf("\nYou entered: ");
    putchar(c);

    return 0;
}