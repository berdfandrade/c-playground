#include <stdio.h>

// Função para desenhar uma grade
void drawGrid(int rows, int columns)
{
    printf("\n\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("+---");
        }
        printf("+\n");

        for (int j = 0; j < columns; j++)
        {
            printf("|   ");
        }
        printf("|\n");
    }

    // Linha inferior da grade
    for (int j = 0; j < columns; j++)
    {
        printf("+---");
    }
    printf("+\n");
}

int main(void)
{
    int put_height;
    int put_width;

    printf("Digite a altura: ");
    scanf("%d", &put_height);

    if (put_height > 20)
    {
        printf("Tamanho máximo da altura é 20\n");
        return 0;
    }

    printf("Digite a largura: ");

    scanf("%d", &put_width);

    if (put_width > 20)
    {
        printf("Tamanho máximo da largura é 20\n");
        return 0;
    }

    drawGrid(put_height, put_width);

    return 0;
}
