/***************************************************
 * Triangle data structure
***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct t_t {
    double x, y;
} t;

typedef struct triangle_t {
    t A, B, C;
} triangle;

double rasT(t P, t Q) {
    return sqrt(pow(P.x - Q.x, 2) + pow(P.y - Q.y, 2));
}

double AB(triangle T) {
    return rasT(T.A, T.B);
}

double AC(triangle T) {
    return rasT(T.A, T.C);
}

double BC(triangle T) {
    return rasT(T.B, T.C);
}

double O(triangle T) {
    return AB(T) + AC(T) + BC(T);
}

double P(triangle T) {
    double s = O(T) / 2;
    return sqrt(s * (s - BC(T)) * (s - AC(T)) * (s - AB(T)));
}

double R(triangle T) {
    return (AB(T) * AC(T) * BC(T) / (4 * P(T)));
}

double O_o(triangle T) {
    return 2 * R(T) * M_PI;
}

double P_o(triangle T) {
    return pow(R(T), 2) * M_PI;
}

double triangleHeight(double side, double P) {
    return (2 * P) / side;
}

double h_a(triangle T) {
    return triangleHeight(BC(T), P(T));
}

double h_b(triangle T) {
    return triangleHeight(AC(T), P(T));
}

double h_c(triangle T) {
    return triangleHeight(AB(T), P(T));
}

int main() {
    triangle T = {{1, 1}, {5, 1}, {2, 6}};
    printf("O = %g\n", O(T));
    printf("P = %g\n", P(T));
    printf("R = %g\n", R(T));
    printf("O_o = %g\n", O_o(T));
    printf("P_o = %g\n", P_o(T));
    printf("h_a = %g\n", h_a(T));
    printf("h_b = %g\n", h_b(T));
    printf("h_c = %g\n", h_c(T));
    return EXIT_SUCCESS;
}