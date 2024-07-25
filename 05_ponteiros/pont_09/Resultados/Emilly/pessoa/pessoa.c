#include <stdio.h>
#include "pessoa.h"
#include <string.h>

tPessoa CriaPessoa()
{
    tPessoa pessoa;
    pessoa.mae = NULL;
    pessoa.pai = NULL;
    pessoa.nome[0] = '\0';

    return pessoa;
}

void LePessoa(tPessoa *pessoa)
{
    scanf("\n%[^\n]", pessoa->nome);
}

int VerificaSeTemPaisPessoa(tPessoa *pessoa)
{
    if (pessoa->mae != NULL || pessoa->pai != NULL)
        return 1;
    return 0;
}
void ImprimePessoa(tPessoa *pessoa)
{
    if (VerificaSeTemPaisPessoa(pessoa))
    {
        printf("NOME COMPLETO: %s\n", pessoa->nome);
        if (pessoa->pai != NULL)
            printf("PAI: %s\n", pessoa->pai->nome);
        else
            printf("PAI: NAO INFORMADO\n");
        if (pessoa->mae != NULL)
            printf("MAE: %s\n", pessoa->mae->nome);
        else
            printf("MAE: NAO INFORMADO\n");
    }
}

void AssociaFamiliasGruposPessoas(tPessoa *pessoas)
{
    int qtd;
    scanf("%d\n", &qtd);

    for (int i = 0; i < qtd; i++)
    {
        int indM, indP, indF;
        scanf("mae: %d, pai:%d, filho: %d\n", &indM, &indP, &indF);
        if (indM > -1)
            pessoas[indF].mae = &pessoas[indM];
        if (indP > -1)
            pessoas[indF].pai = &pessoas[indP];
    }
}