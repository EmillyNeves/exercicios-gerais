#include <stdio.h>
#include <stdlib.h>
#include "matrix_utils.h"

tMatrix *MatrixCreate(int rows, int cols)
{
    tMatrix *mat = (tMatrix *)malloc(sizeof(tMatrix));
    if (mat == NULL)
        exit(1);
    mat->cols = cols;
    mat->rows = rows;
    mat->data = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        mat->data[i] = (int *)malloc(cols * sizeof(int));
    }

    if (mat->data == NULL)
    {
        MatrixFree(mat);
        exit(1);
    }

    return mat;
}

void MatrixFree(tMatrix *matrix)
{
    if (matrix != NULL)
    {
        for (int j = 0; j < matrix->rows; j++)
        {
            free(matrix->data[j]);
        }
        free(matrix->data);
        free(matrix);
    }
}

void MatrixRead(tMatrix *matrix)
{
    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->cols; j++)
        {
            scanf("%d", &matrix->data[i][j]);
        }
    }
}

void MatrixPrint(tMatrix *matrix)
{
    for (int i = 0; i < matrix->rows; i++)
    {
        printf("|");
        for (int j = 0; j < matrix->cols; j++)
        {
            printf("%d", matrix->data[i][j]);
            if (j < matrix->cols - 1)
                printf(" ");
        }
        printf("|\n");
    }
}

int PossibleMatrixSum(tMatrix *matrix1, tMatrix *matrix2)
{
    return matrix1->cols == matrix2->cols && matrix1->rows == matrix2->rows;
}

int PossibleMatrixSub(tMatrix *matrix1, tMatrix *matrix2)
{
    return matrix1->cols == matrix2->cols && matrix1->rows == matrix2->rows;
}

int PossibleMatrixMultiply(tMatrix *matrix1, tMatrix *matrix2)
{
    return matrix1->cols == matrix2->rows;
}

tMatrix *MatrixAdd(tMatrix *matrix1, tMatrix *matrix2)
{
    tMatrix *resultado = MatrixCreate(matrix1->rows, matrix1->cols);

    for (int i = 0; i < matrix1->rows; i++)
    {
        for (int j = 0; j < matrix1->cols; j++)
        {
            resultado->data[i][j] = matrix1->data[i][j] + matrix2->data[i][j];
        }
    }

    return resultado;
}

tMatrix *MatrixSub(tMatrix *matrix1, tMatrix *matrix2)
{
    tMatrix *resultado = MatrixCreate(matrix1->rows, matrix1->cols);

    for (int i = 0; i < matrix1->rows; i++)
    {
        for (int j = 0; j < matrix1->cols; j++)
        {
            resultado->data[i][j] = matrix1->data[i][j] - matrix2->data[i][j];
        }
    }

    return resultado;
}

tMatrix *MatrixMultiply(tMatrix *matrix1, tMatrix *matrix2)
{
    tMatrix *resultado = MatrixCreate(matrix1->rows, matrix2->cols);

    for (int i = 0; i < matrix1->rows; i++)
    {
        for (int j = 0; j < matrix2->cols; j++)
        {
            resultado->data[i][j] = 0;
            for (int k = 0; k < matrix1->cols; k++)
            {
                resultado->data[i][j] += matrix1->data[i][k] * matrix2->data[k][j];
            }
        }
    }

    return resultado;
}

tMatrix *TransposeMatrix(tMatrix *matrix)
{
    tMatrix *resultado = MatrixCreate(matrix->cols, matrix->rows);
    for (int i = 0; i < resultado->rows; i++)
    {
        for (int j = 0; j < resultado->cols; j++)
        {
            resultado->data[i][j] = matrix->data[j][i];
        }
    }
    return resultado;
}

tMatrix *MatrixMultiplyByScalar(tMatrix *matrix, int scalar)
{
    tMatrix *resultado = MatrixCreate(matrix->rows, matrix->cols);
    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->cols; j++)
        {
            resultado->data[i][j] = matrix->data[i][j] * scalar;
        }
    }
    return resultado;
}
