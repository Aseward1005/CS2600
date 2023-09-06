//ternary operator decisionmaking
#include <stdio.h>

int main()
{
    int a, b; //b is unused
    a = 10;

    //printf("The value of b is %d\n", (a == 1) ? 20 : 30);
    b = (a == 1) ? 20 : 30;
    printf("The value of b is %d\n", b);

    //printf("The value of b is %d\n, (a == 10) ? 20 : 30")
    b = (a == 10) ? 20 : 30;
    printf("The value of b is %d\n", b);

    return 0;
}