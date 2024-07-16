#include <stdio.h>
#include "matrix_utils.h"
int main()
{
    int acao = 0, l, c;
    tMatrix mat1, mat2;

    scanf("%d %d", &l, &c);
    mat1 = MatrixCreate(l, c);
    mat1 = MatrixRead(mat1);

    scanf("%d %d", &l, &c);
    mat2 = MatrixCreate(l, c);
    mat2 = MatrixRead(mat2);

    do
    {
        printf("1 - Somar matrizes\n");
        printf("2 - Subtrair matrizes\n");
        printf("3 - Multiplicar matrizes\n");
        printf("4 - Multiplicacao de uma matriz por escalar\n");
        printf("5 - Transposta de uma matriz\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida:\n");

        scanf("%d", &acao);

        if (acao == 6)
            return 0;
        else if (acao == 1)
        {
            if (!PossibleMatrixSum(mat1, mat2))
                printf("Erro: as dimensoes da matriz nao correspondem\n");
            else
                MatrixPrint(MatrixAdd(mat1, mat2));
        }
        else if (acao == 2)
        {
            if (!PossibleMatrixSub(mat1, mat2))
                printf("Erro: as dimensoes da matriz nao correspondem\n");
            else
                MatrixPrint(MatrixSub(mat1, mat2));
        }
        else if (acao == 3)
        {
            if (!PossibleMatrixMultiply(mat1, mat2))
                printf("Erro: o numero de colunas da primeira matriz eh diferente do numero de linhas da segunda matriz\n");
            else
                MatrixPrint(MatrixMultiply(mat1, mat2));
        }
        else if (acao == 4)
        {

            int mat, escalar;
            scanf("%d %d", &escalar, &mat);
            if (mat == 1)
            {
                mat1 = MatrixMultiplyByScalar(mat1, escalar);
                MatrixPrint(mat1);
            }
            else if (mat == 2)
            {
                mat2 = MatrixMultiplyByScalar(mat2, escalar);
                MatrixPrint(mat2);
            }
        }
        else if (acao == 5)
        {
            MatrixPrint(TransposeMatrix(mat1));
            MatrixPrint(TransposeMatrix(mat2));
        }
    } while (acao != 6);

    return 0;
}