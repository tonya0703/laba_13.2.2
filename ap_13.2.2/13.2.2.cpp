#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define CONSTANT 10  
#define IS_ALPHA(c) isalpha(c)
#define IS_DIGIT(c) isdigit(c)
#define SIZE 100

void Matrix(int rows, int columns)
{
    int matrix[SIZE][SIZE];
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            matrix[i][j] = rand();
        }
    }
    printf("\nGenerated Matrix:\n");
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char string[100];
    int acount = 0;
    int dcount = 0;
    int rows = 0, columns = 0;

    printf("Enter a string: ");
    fgets(string, SIZE, stdin);

    for (int i = 0; string[i] != '\0'; i++)
    {
        if (IS_ALPHA(string[i])) {
            acount++;
        }
        else if (IS_DIGIT(string[i])) {
            dcount++;
        }
    }

    printf("Alphabetic characters: %d\n", acount);
    printf("Numeric characters: %d\n", dcount);

    for (int i = 0; string[i] != '\0'; i++) {
        char h = string[i];
        if (IS_DIGIT(h) && atoi(&h) > 0) {
            rows = atoi(&h);
            break;
        }
    }

    for (int i = 0; string[i] != '\0'; i++) {
        if (IS_ALPHA(string[i])) {
            columns = string[i] / CONSTANT;
            break;
        }
    }
    printf("Rows and columns = %d and %d", rows, columns);
    if (rows > 0 && columns > 0) {
        Matrix(rows, columns);
    }
    else {
        printf("Incorrect string\n");
    }
}