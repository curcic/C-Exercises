/****************************************************
 * User interface demo
****************************************************/

#include <stdio.h>
#include <stdlib.h>

#define Width 50

void symbolRow(char symbol) {
    int i = 0;
    for (i = 0; i < Width; i++) {
        printf("%c", symbol);
    }
    printf("\n");
}

int stringLength(char string[]) {
    int length = 0;
    while (string[length] != '\0') {
        length++;
    }
    return length;
}

void rowName(char name[], char symbol) {
    int i = 0, spaceNum = (Width - 2 - stringLength(name)) / 2;
    char rowName[Width + 1];
    rowName[i++] = symbol;
    while (i < spaceNum) {
        rowName[i] = ' ';
        i++;
    }
    while (name[i - spaceNum] != '\0') {
        rowName[i] = name[i - spaceNum];
        i++;
    }
    while (i < Width - 1) {
        rowName[i] = ' ';
        i++;
    }
    rowName[i++] = symbol;
    rowName[i] = '\0';
    printf("%s\n", rowName);
}

void drawUI() {
    char symbol = '#';
    symbolRow(symbol);
    char title[] = "Whole Num Sum";
    rowName(title, symbol);
    symbolRow(symbol);
}

int main() {
    drawUI();
    return EXIT_SUCCESS;
}