#include <stdio.h>
#include "utils.h"
#include <stdlib.h>
int main()
{

    int linhas, colunas;

    scanf("%d %d", &linhas, &colunas);
    int **mat = CriaMatriz(linhas, colunas);

    LeMatriz(mat, linhas, colunas);
    ImprimeMatrizTransposta(mat, linhas, colunas);

    LiberaMatriz(mat, linhas);

    return 0;
}