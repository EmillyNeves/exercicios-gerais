#include "vetor.h"
#include <stdio.h>

void LeDadosParaVetor(int *vet, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        scanf("%d", &vet[i]);
    }
}

void ImprimeDadosDoVetor(int *n, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        printf("%d ", n[i]);
    }
    printf("\n");
}

void TrocaSeAcharMenor(int *vet, int tam, int *paraTrocar)
{
    int aux;
    for (int i = 0; i < tam; i++)
    {
        if (*paraTrocar < vet[i])
        {
            aux = vet[i];
            vet[i] = *paraTrocar;
            *paraTrocar = aux;
            break;
        }
    }
}
void OrdeneCrescente(int *vet, int tam)
{

    for (int j = 0; j < tam; j++)
    {        for (int i = j; i < tam; i++)
        {
            TrocaSeAcharMenor(vet, tam, &vet[i]);
        }
    }
}
