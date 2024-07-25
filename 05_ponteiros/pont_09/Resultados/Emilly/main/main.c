#include <stdio.h>
#include "pessoa.h"
int main()
{
    int qtdP;
    scanf("%d\n", &qtdP);
    tPessoa pessoas[qtdP];

    for (int i = 0; i < qtdP; i++)
    {
        pessoas[i] = CriaPessoa();
        LePessoa(&pessoas[i]);
    }
    AssociaFamiliasGruposPessoas(pessoas);

    for (int i = 0; i < qtdP; i++)
    {
            ImprimePessoa(&pessoas[i]);
    }

    return 0;
}