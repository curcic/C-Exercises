/********************************************
 * Write a program that enables the user to input a string.
 * The variable takes a maximum of 100 characters including the NULL character.
 * Use the 'character by character' method.
 * Count the occurrences of a digit
 * Count the occurrences of a single digit in the written string
 * Count the occurrences of all letters in the written string
 * Count the occurrences of all capital letters in the written string
 * Count the occurrences of all lower case letters in the written string
********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define len 100

int inputRow(char *string) {
    char c = 'x', i = 0;
    while (c != '\n' && i < len - 1) {
        c = getchar();
        string[i] = c;
        i++;
    }
    string[i - 1] = '\0';
    return i;
}

int digitNumber(char *string) {
    int digit_number = 0, i = 0;
    while (string[i] != '\0') {
        if (isdigit(string[i])) {
            digit_number++;
        }
        i++;
    }
    return digit_number;
}

void singleDigitNumber(char *string) {
    int digit_number[10] = {0};
    int i = 0;
    while (string[i] != '\0') {
        int index = string[i] - '0';
        if (index >= 0 && index <= 9) {
            digit_number[index]++;
        }
        i++;
    }
    for (i = 0; i < 10; i++) {
        if (digit_number[i] != 0) {
            printf("The digit %d is repeated %d times.\n", i, digit_number[i]);
        }
    }
}

int countLetters(char *string) {
    int i = 0;
    int letter_number = 0;
    while (string[i] != '\0') {
        if (isalpha(string[i])) {
            letter_number++;
        }
        i++;
    }
    return letter_number;
}

int countCapitalLetters(char *string) {
    int i = 0;
    int letter_number = 0;
    while (string[i] != '\0') {
        if (isupper(string[i])) {
            letter_number++;
        }
        i++;
    }
    return letter_number;
}

int countLowerLetters(char *string) {
    int i = 0;
    int letter_number = 0;
    while (string[i] != '\0') {
        if (islower(string[i])) {
            letter_number++;
        }
        i++;
    }
    return letter_number;
}

void countSelfCapitalLetters(char *string) {
    int letter_number[26] = {0};
    int i = 0;
    while (string[i] != '\0') {
        int index = string[i] - 'A';
        if (index >= 0 && index < 26) {
            letter_number[index]++;
        }
        i++;
    }
    for (i = 0; i < 26; i++) {
        if (letter_number[i] != 0) {
            printf("The letter %c is repeated %d times.\n", 'A' + i, letter_number[i]);
        }
    }
}

void countSelfLowerLetters(char *string) {
    int letter_number[26] = {0};
    int i = 0;
    while (string[i] != '\0') {
        int index = string[i] - 'a';
        if (index >= 0 && index < 26) {
            letter_number[index]++;
        }
        i++;
    }
    for (i = 0; i < 26; i++) {
        if (letter_number[i] != 0) {
            printf("The letter %c is repeated %d times.\n", 'a' + i, letter_number[i]);
        }
    }
}

void countSelfLetters(char *string) {
    int letter_number[26] = {0};
    int i = 0;
    while (string[i] != '\0') {
        int index = toupper(string[i]) - 'A';
        if (index >= 0 && index < 26) {
            letter_number[index]++;
        }
        i++;
    }
    for (i = 0; i < 26; i++) {
        if (letter_number[i] != 0) {
            printf("The letter %c (or %c) is repeated %d times.\n", 'A' + i, 'a' + i, letter_number[i]);
        }
    }
}

int main() {
    char string[len];
    printf("Please input a string: ");
    inputRow(string);
    printf("The number of digits in the string is: %d\n", digitNumber(string));
    singleDigitNumber(string);
    printf("The number of letters in the string is: %d\n", countLetters(string));
    printf("The number of lowercase letters in the string is: %d\n", countLowerLetters(string));
    printf("The number of uppercase letters in the string is: %d\n", countCapitalLetters(string));
    countSelfCapitalLetters(string);
    countSelfLowerLetters(string);
    countSelfLetters(string);
    return EXIT_SUCCESS;
}