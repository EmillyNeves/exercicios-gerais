#include <stdio.h>
#include "utils.h"

void LeNumeros(int *array, int tamanho)
{
    for (int i = 0; i < tamanho; i++)
    {
        scanf("%d ", &array[i]);
    }
}

void EncontraMaiorMenorMedia(int *array, int tamanho, int *maior, int *menor, float *media)
{
    *menor = array[tamanho - 1];
    *maior = array[0];
    *media = 0;
    for (int i = 0; i < tamanho; i++)
    {
        if (array[i] > *maior)
            *maior = array[i];
        if (array[i] < *menor)
            *menor = array[i];
        *media += array[i];
    }
    *media /= (float)(tamanho);
}