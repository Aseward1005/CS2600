#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3
#define MAX 9

void squareGen(int matrix[SIZE][SIZE]);
int checkSquare(int matrix[SIZE][SIZE]);
void printSquare(int matrix[SIZE][SIZE]);

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

int checkSquare(int matrix[SIZE][SIZE]){
    //check first row to get a sum
    int sum = 0;
    for (int i = 0; i < SIZE; i++){
        sum += matrix[0][i];
    }

    //check rest of rows
    int curr;
    for (int i = 1; i < SIZE; i++){
        //reset current
        curr = 0;
        for (int j = 0; j < SIZE; j++){
            curr += matrix[i][j];
        }
        //check if we keep going
        if (curr != sum)
            return 0;
    }

    //check verticals
    //same but indices are flipped
    for (int i = 0; i < SIZE; i++) {
        curr = 0;
        for (int j = 0; j < SIZE; j++) {
            curr += matrix[j][i];
        }
        if (curr != sum)
            return 0;
    }

    //check diagonals
    // diagonal from top left to bottom right
    curr = 0;
    for (int i = 0; i < SIZE; i++) {
        curr += matrix[i][i];
    }
    if (curr != sum)
        return 0;

    //diagonal from bottom left to top right
    curr = 0;
    for (int i = 0; i < SIZE; i++){
        curr += matrix[i][SIZE-1-i];
    }
    if (curr != sum)
        return 0;

    return 1;
}

void squareGen(int matrix[SIZE][SIZE]){
    //generate the matrix
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            matrix[i][j] = j + SIZE*i + 1;
        }
    }

    //shuffle the matrix
    int temp;
    int randomRow;
    int randomCol;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            //save current value
            temp = matrix[i][j];

            //generate random target of swap
            randomRow = rand() % SIZE;
            randomCol = rand() % SIZE;

            //swap the values
            matrix[i][j] = matrix[randomRow][randomCol];
            matrix[randomRow][randomCol] = temp;
        }
    }
    
    //debug check
    //printSquare(matrix);
}

void printSquare(int matrix[SIZE][SIZE]){
    for (int i = 0; i < SIZE; i++) {
        printf("[ ");
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("]\n");
    }
}