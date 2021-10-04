/*********************************************
 * Write a program that enables the user to generate a matrix with dimensions n X n, n - 5
 * Matrix elements are pseudo-rand whole numbers from the interval [10, 100).
 * Show the matrix on the STD
 * Separate the main and secondary matrix to seperate outputs
 * Show the diagonals on the STD
 * Define the diagonal minimum and show it on the STD
*********************************************/

#include <stdio.h>
#include <stdlib.h>

#define n 5

void generateMatrix(int matrix[][n]) {
    int i = 0, j = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            matrix[i][j] = 10 + rand() % (100 - 10);
        }
    }
}

void showMatrix(int matrix[][n]) {
    int i = 0, j = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void separateMain(int matrix[][n], int m_diag[]) {
    int i = 0;
    for (i = 0; i < n; i++) {
        m_diag[i] = matrix[i][i];
    }
}

void separateSecondary(int matrix[][n], int s_diag[]) {
    int i = 0;
    for (i = 0; i < n; i++) {
        s_diag[i] = matrix[i][n - i - 1];
    }
}

void showArray(int array[]) {
    int i = 0;
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
int minArray(int array[]) {
    int i = 0;
    int min = array[0];
    for (i = 1; i < n; i++) {
        if (min > array[i]) {
            min = array[i];
        }
    }
    return min;
}

int main() {
    int matrix[n][n];
    int m_diag[n] = {0};
    int s_diag[n] = {0};
    generateMatrix(matrix);
    showMatrix(matrix);
    printf("Main diagonal: ");
    separateMain(matrix, m_diag);
    showArray(m_diag);
    printf("Second diagonal: ");
    separateSecondary(matrix, s_diag);
    showArray(s_diag);
    printf("Main diagonal minimum: %d\n", minArray(m_diag));
    printf("Secondary diagonal minimum: %d\n", minArray(s_diag));
    return EXIT_SUCCESS;
}