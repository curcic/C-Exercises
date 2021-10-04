/***************************************************
 * Recrusion
 * The function should call itself
 * n! = n * [(n - 1) * ... * 2 * 1]
 * n! = n * (n - 1)
 * 5! = 5 * 4 * 3 * 2 * 1 = 5 * 4! = 5 * 4 * 3!
***************************************************/

#include <stdio.h>
#include <stdlib.h>

int fakt_i(int n) {
    int i = 0, fakt = 1;
    for (i = 0; i < n; i++) {
        fakt *= (i + 1);
    }
    return fakt;
}

int fakt_r(int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return n * fakt_r(n - 1);
    }
}

int main() {
    int n = 10;
    printf("n! = %d\n", fakt_i(n));
    printf("n! = %d\n", fakt_r(n));
}