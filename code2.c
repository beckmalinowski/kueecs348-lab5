#include <stdlib.h>
#include <stdio.h>
#define SIZE 5

void printMatrix(int m[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]) {
    int res[SIZE][SIZE] = {{0}};

    for (int i = 0; i < SIZE; i++) { // iterate rows
        for (int j = 0; j < SIZE; j++) { // iterate columns
            res[i][j] = m1[i][j] + m2[i][j];
        }
    }

    printMatrix(res);
}

void multiplyMatrices(int m1[SIZE][SIZE], int m2[SIZE][SIZE]) {
    int res[SIZE][SIZE] = {{0}}; // since the size of a multiplied matrix is m x p where
                         // m1 is size m x n and m2 is n x p

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                // m1 should multiply by rows, m2 should multiply by columns
                res[i][j] += (m1[i][k] * m2[k][j]);
            }
        }
    }

    printMatrix(res);
}

void transposeMatrix(int m[SIZE][SIZE]) {
    int res[SIZE][SIZE] = {{0}};

    for (int i = 0; i < SIZE; i++) { // iterate rows
        for (int j = 0; j < SIZE; j++) { // iterate columns
            res[j][i] = m[i][j];
        }
    }

    printMatrix(res);
}

int main() {
    int m1[SIZE][SIZE] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    int m2[SIZE][SIZE] = {
        {25, 24, 23, 22, 21},
        {20, 19, 18, 17, 16},
        {15, 14, 13, 12, 11},
        {10, 9, 8, 7, 6},
        {5, 4, 3, 2, 1}
    };

    printf("m1: \n");
    printMatrix(m1);

    printf("\nm2: \n");
    printMatrix(m2);

    printf("\nm1 + m2: \n");
    addMatrices(m1, m2);

    printf("\nm1*m2\n");
    multiplyMatrices(m1, m2);

    printf("\nm2*m1\n");
    multiplyMatrices(m2, m1);

    printf("\nm1 transposed: \n");
    transposeMatrix(m1);

    printf("\nm2 transposed: \n");
    transposeMatrix(m2);
}
