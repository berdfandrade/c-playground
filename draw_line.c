#include <stdio.h>

int main(void)
{
    int rows = 5;
    int columns = 5;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("+---");
        }
        printf("+\n");

        for (int j = 0; j < columns; j++) {
            printf("|   ");
        }
        printf("|\n");
    }

    // Linha inferior da grade
    for (int j = 0; j < columns; j++) {
        printf("+---");
    }
    printf("+\n");
    return 0;
}