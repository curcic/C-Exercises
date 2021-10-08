/********************************************
 * Dynamic Memory Allocation + 2D ARR
 * Write a program that, for already given sizes of rows and columns, alocates memory for the table, generates pseudo-random numbers in range [1, 10) and frees the memory after outputing to the STD
********************************************/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int r = 10, k = 20, i = 0, j = 0;
    int **table = (int **)malloc(r * sizeof(int *));
    if (table == NULL) {
        printf("ERROR!\n");
        return EXIT_FAILURE;
    }
    for (i = 0; i < r; i++) {
        table[i] = (int *)malloc(k * sizeof(int));
        if (table[i] == NULL) {
            printf("ERROR!\n");
            return EXIT_FAILURE;
        }
    }
    for (i = 0; i < r; i++) {
        for (j = 0; j < k; j++) {
            table[i][j] = 1 + rand() % 9;
        }
    }
    for (i = 0; i < r; i++) {
        for (j = 0; j < k; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
    for (i = 0; i < r; i++) {
        free(table[i]);
    }
    free(table);
    return EXIT_SUCCESS;
}