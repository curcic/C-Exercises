/*****************************************************
 * File handling
*****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main() {
    FILE *f;
    f = fopen("C\\Tekst\\example.txt", "r");
    assert(f != NULL && "File does not exist");
    char c = ' ';
    while ((c = fgetc(f)) != EOF) {
        printf("%c", c);
    }
    printf("\n");
    fclose(f);
    return EXIT_SUCCESS;
}