#include "matrix_utils.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int rows1 = 0;
    int cols1 = 0;
    int rows2 = 0;
    int cols2 = 0;
    int option = 0;

    scanf("%d %d", &rows1, &cols1);
    int matrix1[rows1][cols1];
    matrix_read(rows1, cols1, matrix1);

    scanf("%d %d", &rows2, &cols2);
    int matrix2[rows2][cols2];
    matrix_read(rows2, cols2, matrix2);

    while (option != 6)
    {
        printf("1 - Somar matrizes\n2 - Subtrair matrizes\n3 - Multiplicar matrizes\n4 - Multiplicacao de uma matriz por escalar\n5 - Transposta de uma matriz\n6 - Encerrar o programa\n");
        scanf("%d", &option);
        printf("Opcao escolhida: \n");

        if (option == 1)
        {
            if (!possible_matrix_sum(rows1, cols1, rows2, cols2))
            {
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
                continue;
            }

            int result[rows1][cols1];

            matrix_add(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
            matrix_print(rows1, cols1, result);
        }

        else if (option == 2)
        {
            if (!possible_matrix_sub(rows1, cols1, rows2, cols2))
            {
                printf("Erro: as dimensoes da matriz nao correspondem\n\n");
                continue;
            }

            int result[rows1][cols1];

            matrix_sub(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
            matrix_print(rows1, cols1, result);
        }

        else if (option == 3)
        {
            if (!possible_matrix_multiply(cols1, rows2))
            {
                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n\n");
                continue;
            }

            int result[rows1][cols2];

            matrix_multiply(rows1, cols1, matrix1, rows2, cols2, matrix2, result);
            matrix_print(rows1, cols2, result);
        }

        else if (option == 4)
        {
            int scalar = 0;
            int whichMatrix = 0;

            scanf("%d %d", &scalar, &whichMatrix);

            if (whichMatrix == 1) {
                scalar_multiply(rows1, cols1, matrix1, scalar);
                matrix_print(rows1, cols1, matrix1);
                continue;
            }

            scalar_multiply(rows2, cols2, matrix2, scalar);
            matrix_print(rows2, cols2, matrix2);
        }

        else if (option == 5)
        {
            int result1[cols1][rows1];
            int result2[cols2][rows2];

            transpose_matrix(rows1, cols1, matrix1, result1);
            transpose_matrix(rows2, cols2, matrix2, result2);

            matrix_print(cols1, rows1, result1);
            matrix_print(cols2, rows2, result2);
        }
    }

    return 0;
}
