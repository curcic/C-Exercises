/*********************************************
 * Generate an array of pseudo-random numbers
 * n = 100
 * Create a function for every operation
 * Move every letter by one position alphabetically
 * Move every letter by x > 0 position alphabetically (where x is defined by the user)
********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

#define n 19

void generateString(char *string) {
    int i = 0;
    for (i = 0; i < n; i++) {
        string[i] = 'A' + rand() % 26;
    }
    string[n] = '\0';
}

void toLower(char *string, char *result) {
    int i = 0;
    for (i = 0; i < n; i++) {
        result[i] = tolower(string[i]);
    }
    result[n] = '\0';
}

void moveString(char *string, char *result) {
    int i = 0;
    for (i = 0; i < n; i++) {
        result[i] = 'A' + (string[i] + 1 - 'A') % 26; 
    }
    result[n] = '\0';
}

void moveXString(char *string, char *result, int x) {
    int i = 0;
    for (i = 0; i < n; i++) {
        result[i] = 'A' + (string[i] + x - 'A') % 26;
    }
    result[n] = '\0';
}

int main() {
    char string[n + 1];
    generateString(string);
    printf("Generated string: %s\n", string);
    char lower_string[n + 1];
    toLower(string, lower_string);
    printf("To lower: %s\n", lower_string);
    char move_string[n + 1];
    moveString(string, move_string);
    printf("Moved by one: %s\n", move_string);
    int x = 0;
    printf("x = ");
    scanf("%d", &x);
    assert(x > 0);
    char move_x_string[n + 1];
    moveXString(string, move_x_string, x);
    printf("Move by x: %s\n", move_x_string);
}