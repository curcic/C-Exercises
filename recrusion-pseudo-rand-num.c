/***************************************************
 * The user inputs a number n > 0
 * Generate a pseudo-random array in an interval [0, 1)
 * Use recrusion to calculate the array sum
***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void showArray(double *array, int n) {
    int i = 0;
    while (i < n) {
        printf("%g ", array[i++]);
    }
    printf("\n");
}

void generateArray(double *array, int n) {
    int i = 0;
    while (i < n) {
        array[i++] = (double) rand() / RAND_MAX;
    }
}

double sum(double *array, int n) {
    if (n == 0) {
        return array[n];
    }
    else if (n == 1 || n == 2) {
        return array[n] + sum(array, n - 1);
    }
    else {
        return array[n] + sum(array, n - 2);
    }
}

int main() {
    int n = 0;
    printf("n = ");
    scanf("%d", &n);
    assert(n > 0);
    double *array = (double *)malloc(n * sizeof(double));
    assert(array != NULL);
    generateArray(array, n);
    showArray(array, n);
    printf("The sum is: %g\n", sum(array, n));
    free(array);
    return EXIT_SUCCESS;
}