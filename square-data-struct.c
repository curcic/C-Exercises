/***************************************************
 * Square data structure
***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define n 4

typedef struct t_t {
    double x, y;
} t;

typedef struct square_t {
    t TT[n];
} square;

int main() {
    double d = 2, a = d / sqrt(2);
    square k;
    k.TT[0].x = 1; k.TT[0].y = 1;
    k.TT[1].x = k.TT[0].x + a; k.TT[1].y = k.TT[0].y;
    k.TT[2].x = k.TT[0].x + a; k.TT[2].y = k.TT[0].y + a;
    k.TT[3].x = k.TT[0].x; k.TT[3].y = k.TT[0].y + a;
    int i;
    for (i = 0; i < n; i++) {
        printf("%c = (%g, %g)\n", 'A' + i, k.TT[i].x, k.TT[i].y);
    }
    printf("O = %g\nP = %g\n", 4 * a, pow(a, 2));
    return EXIT_SUCCESS;
}