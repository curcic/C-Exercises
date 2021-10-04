/***************************************************
 * The user inputs a whole number n > 0
 * Calculate the sum of the first n natural numbers
 * Use recrusion
***************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int sum(int n) {
    if (n == 0) {
        return 0;
    }
    else {
        return n + sum(n -1);
    }
}

int main() {
    int n = 0;
    printf("n = ");
    scanf("%d", &n);
    assert(n > 0);
    printf("The sum is: %d\n", sum(n));
    return EXIT_SUCCESS;
}