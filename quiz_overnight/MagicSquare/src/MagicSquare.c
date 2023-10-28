#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/matrix.h"

int main(void){
    srand(time(NULL));

    int matrix[SIZE][SIZE];
    int times = 0;
    squareGen(matrix);

    /*
    //TEST SECTION
    int test[SIZE][SIZE] = {{4, 9, 2},
                            {3, 5, 7},
                            {8, 1, 6}};
    printf("%d", checkSquare(test));
    //squareGen(test);
    //printSquare(test);
    */

    while (!checkSquare(matrix)) {
        squareGen(matrix);
        checkSquare(matrix);
        times++;
    }

        printf("found a magic square after %d times\n", times);
        printSquare(matrix);
    
    return EXIT_SUCCESS;
}