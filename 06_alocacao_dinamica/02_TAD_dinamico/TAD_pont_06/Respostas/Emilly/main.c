#include <stdio.h>
#include <stdlib.h>
#include "matrix_utils.h"

int main()
{
    int rows, cols, op, scalar, opMatrix;
    tMatrix *matrix1 = NULL, *matrix2 = NULL, *resultado = NULL;
    int encerrar = 0;

    scanf("%d %d", &rows, &cols);
    matrix1 = MatrixCreate(rows, cols);
    MatrixRead(matrix1);

    scanf("%d %d", &rows, &cols);
    matrix2 = MatrixCreate(rows, cols);
    MatrixRead(matrix2);

    while (1)
    {
        printf("1 - Somar matrizes\n");
        printf("2 - Subtrair matrizes\n");
        printf("3 - Multiplicar matrizes\n");
        printf("4 - Multiplicacao de uma matriz por escalar\n");
        printf("5 - Transposta de uma matriz\n");
        printf("6 - Encerrar o programa\n");

        printf("Opcao escolhida: \n");
        scanf("%d", &op);

        if (op == 6)
        {
            MatrixFree(matrix1);
            MatrixFree(matrix2);
            break;
        }
        else if (op == 1)
        {
            if (PossibleMatrixSum(matrix1, matrix2))
            {
                resultado = MatrixAdd(matrix1, matrix2);
                MatrixPrint(resultado);
                MatrixFree(resultado);
            }
            else
                printf("Erro: as dimensoes da matriz nao correspondem\n");
        }
        else if (op == 2)
        {
            if (PossibleMatrixSub(matrix1, matrix2))
            {
                resultado = MatrixSub(matrix1, matrix2);
                MatrixPrint(resultado);
                MatrixFree(resultado);
            }
            else
                printf("Erro: as dimensoes da matriz nao correspondem\n");
        }
        else if (op == 3)
        {
            if (PossibleMatrixMultiply(matrix1, matrix2))
            {
                resultado = MatrixMultiply(matrix1, matrix2);
                MatrixPrint(resultado);
                MatrixFree(resultado);
            }
            else
                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n");
        }
        else if (op == 4)
        {
            scanf("%d %d", &scalar, &opMatrix);
            if (opMatrix == 1)
            {
                resultado = MatrixMultiplyByScalar(matrix1, scalar);
                MatrixPrint(resultado);
                MatrixFree(matrix1);
                matrix1 = resultado;
            }
            else if (opMatrix == 2)
            {
                resultado = MatrixMultiplyByScalar(matrix2, scalar);
                MatrixPrint(resultado);
                MatrixFree(matrix2);
                matrix2 = resultado;
            }
        }
        else if (op == 5)
        {
            resultado = TransposeMatrix(matrix1);
            MatrixPrint(resultado);
            MatrixFree(resultado);

            resultado = TransposeMatrix(matrix2);
            MatrixPrint(resultado);
            MatrixFree(resultado);
        }
    }

    return 0;
}