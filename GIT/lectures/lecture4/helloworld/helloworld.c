#include <stdio.h> //only the functions being called will be linked in, increases link time but not runtime

int main() //function signature
{
    printf("Hello, World!"); //printing to the console is a side effect
    return 0; //taking this class after taking os is a crazy experience
}