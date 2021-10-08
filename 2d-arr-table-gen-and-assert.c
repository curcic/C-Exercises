/*********************************************
 * Write a program that enables the user to input a and b where a > b
 * Generate a table dimensions rXk, r = 4, k = 10
 * Elements are pseudo-random numbers, (0 <= d <= 5).
 * Check if the user input is correct
*********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

#define r 4
#define k 10
#define max_d 5

void mySwap(double *x, double *y) {
    double c = *x;
    *x = *y;
    *y = c;
}

void inputDouble(double *x, char c) {
    printf("%c = ", c); scanf("%lf", x);
}

void inputAB(double *a, double *b) {
    inputDouble(a, 'a');
    inputDouble(b, 'b');
    if (a > b) {
        mySwap(a, b);
    }
}

void inputInt(int *x, char c) {
    printf("%c = ", c); scanf("%d", x);
}

void inputD(int *d) {
    inputInt(d, 'd');
    if (*d < 0) { *d = 0; }
    if (*d > max_d) { *d = max_d; }
}

double generateElement(double a, double b, int d) {
    double s = pow(10, d);
    return round(a + (b - a) * ((double)rand() / RAND_MAX) * s) / s;
}

void showTable(double table[][k]) {
    int i = 0, j = 0;
    for (i = 0; i < r; i++) {
        for (j = 0; j < k; j++) {
            printf("%.6lf", table[i][j]);
        }
        printf("\n");
    }
}

void generateTable(double table[][k], double a, double b, int d) {
    int i = 0, j = 0;
    for (i = 0; i < r; i++) {
        for (j = 0; j < r; j++) {
            table[i][j] = generateElement(a, b, d);
        }
    }
}

void exchangeColumns(double table[][k], int m, int n) {
    int i = 0;
    for (i = 0; i < r; i++) {
        mySwap(&table[i][m - 1], &table[i][n - 1]);
    }
}

void inputValidInt(int *x, char c) {
    inputInt(x, c);
    assert((*x > 0 && *x <= k) && "ERROR");
}

int main() {
    int m = 0, n = 0, d = 0;
    double a = 0, b = 0, table[r][k] = {0};
    inputAB(&a, &b);
    inputD(&d);
    generateTable(table, a, b, d);
    showTable(table);
    inputValidInt(&m, 'm');
    inputValidInt(&n, 'n');
    exchangeColumns(table, m, n);
    showTable(table);
    return EXIT_SUCCESS;
}