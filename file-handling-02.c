/*****************************************************
 * File handling
*****************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main() {
    FILE *f = fopen("C\\Tekst\\entrance.txt", "w");
    assert(f != NULL && "ERROR");
    char string[] = "Some text...";
    fprintf(f, "%s\n", string);
    printf("Writing finished.\n");
    fclose(f);
    return EXIT_SUCCESS;
}