//if elseif else decision making
#include <stdio.h>

int main()
{
    int a = 20;

    if(a == 10)
        printf("value of a is 10\n");
    else if(a == 20)
        printf("value of a is 20\n");
    else if(a == 30)
        printf("value of a is 30\n");
    else
        printf("None of the values match\n");

    printf("Exact value is: %d\n", a);

    return 0;
}