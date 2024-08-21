#include <stdio.h>
#include "utils_char.h"
#include <stdlib.h>

char *CriaVetor(int tamanho)
{
    char *vet = (char *)calloc(tamanho, sizeof(char *));
    if (vet == NULL)
    {
        printf("ERRO\n");
        exit(1);
    }
    for (int i = 0; i < tamanho; i++)
    {
        vet[i] = '_';
    }

    return vet;
}

void LeVetor(char *vetor, int tamanho)
{
    int i = 0;
    char c;
    while (scanf("%c", &c) == 1 && i != tamanho)
    {
        if (c == '\n')
            break;
        vetor[i] = c;
        i++;
    }
}

void ImprimeString(char *vetor, int tamanho){
    printf("%s\n", vetor);
}

void LiberaVetor(char *vetor){
    free(vetor);
}