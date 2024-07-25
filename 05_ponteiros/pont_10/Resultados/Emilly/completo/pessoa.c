#include <stdio.h>
#include "pessoa.h"

tPessoa CriaPessoa()
{
    tPessoa pessoa;
    pessoa.nome[0] = '\0';
    pessoa.mae = NULL;
    pessoa.pai = NULL;
    pessoa.irmao = NULL;
    return pessoa;
}
void LePessoa(tPessoa *pessoa)
{
    scanf("\n%[^\n]", pessoa->nome);
}
int VerificaSeTemPaisPessoa(tPessoa *pessoa)
{
    if (pessoa->pai != NULL || pessoa->mae != NULL)
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
        if (pessoa->irmao != NULL)
            printf("IRMAO: %s\n\n", pessoa->irmao->nome);
        else
            printf("IRMAO: NAO INFORMADO\n\n");
    }
}
int VerificaIrmaoPessoa(tPessoa *pessoa1, tPessoa *pessoa2)
{
    return (pessoa1->mae == pessoa2->mae && pessoa1->pai == pessoa2->pai);
}
void AssociaFamiliasGruposPessoas(tPessoa *pessoas, int numPessoas)
{
    int qtdAsso;
    scanf("%d\n", &qtdAsso);
    for (int i = 0; i < qtdAsso; i++)
    {
        int indM, indP, indF;
        scanf("mae: %d, pai:%d, filho: %d\n", &indM, &indP, &indF);
        if (indM > -1)
            pessoas[indF].mae = &pessoas[indM];
        if (indP > -1)
            pessoas[indF].pai = &pessoas[indP];
    }

    for (int i = 0; i < numPessoas; i++)
    {
        for (int j = i + 1; j < numPessoas; j++)
        {
            if (VerificaIrmaoPessoa(&pessoas[i], &pessoas[j]))
            {
                pessoas[i].irmao = &pessoas[j];
                pessoas[j].irmao = &pessoas[i];
            }
        }
    }
}