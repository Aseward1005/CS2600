#include <stdio.h>
#include <string.h>

union Data 
{
    int i;
    double f;
    char str[20];
};

int main() 
{
    union Data data;

    printf("---Correct usage ---\n");
    data.i = 10;
    printf("data.i : %d\n", data.i);
    data.f = 220.5;
    printf("data.f : %f\n", data.f);
    strcpy(data.str, "C Programming");
    printf("data.str, %s\n", data.str);
    printf("\n");

    printf("---Incorrect usage---\n");
    printf("data.i : %d\n", data.i);
    printf("data.f : %f\n", data.f);
    printf("data.str : %s\n", data.str);
}