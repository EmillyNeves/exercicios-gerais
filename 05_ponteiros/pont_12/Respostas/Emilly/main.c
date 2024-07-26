#include <stdio.h>
#include "vetor.h"
int soma(int n1, int n2)
{
    return n1 + n2;
}
int produto(int n1, int n2)
{
    return n1 * n2;
}
int main()
{
    Vetor vet;
    int s, p;

    LeVetor(&vet);
    s = AplicarOperacaoVetor(&vet, soma);
    p = AplicarOperacaoVetor(&vet, produto);

    printf("Soma: %d\n", s);
    printf("Produto: %d\n", p);

    return 0;
}