#include <stdio.h>
#include <stdlib.h>
#include "banco.h"

#define QTD_CONTAS_ALOCADAS 5

tBanco *CriaBanco()
{
    tBanco *banco = (tBanco *)malloc(sizeof(tBanco));

    if (banco == NULL)
    {
        printf("Erro na alocacao de memoria do banco ");
        return banco;
    }

    banco->contasAlocadas = QTD_CONTAS_ALOCADAS;
    banco->qtdContas = 0;

    banco->contas = (tConta **)malloc(banco->contasAlocadas * sizeof(tConta *));
    if (banco->contas == NULL)
    {
        printf("Erro na alocacao de memoria no vetor de contas do banco");
        DestroiBanco(banco);
    }
    return banco;
}

void AbreContaBanco(tBanco *banco)
{
    if (banco->contasAlocadas == banco->qtdContas)
    {
        banco->contasAlocadas += QTD_CONTAS_ALOCADAS;
        banco->contas = (tConta **)realloc(banco->contas, banco->contasAlocadas * sizeof(tConta *));
        if ((*banco).contas == NULL)
        {
            printf("Erro na realocacao de memoria no vetor de contas do banco!\n");
            DestroiBanco(banco);
        }
    }
    banco->contas[banco->qtdContas] = CriaConta();
    LeConta(banco->contas[banco->qtdContas]);
    banco->qtdContas++;
}

void SaqueContaBanco(tBanco *banco)
{
    int numConta;
    float valor;
    scanf("%d %f\n", &numConta, &valor);
    for (int i = 0; i < banco->qtdContas; i++)
    {
        if (VerificaConta(banco->contas[i], numConta))
        {
            SaqueConta(banco->contas[i], valor);
            break;
        }
    }
}

void DepositoContaBanco(tBanco *banco)
{
    int numConta;
    float valor;
    scanf("%d %f\n", &numConta, &valor);
    for (int i = 0; i < banco->qtdContas; i++)
    {
        if (VerificaConta(banco->contas[i], numConta))
        {
            DepositoConta(banco->contas[i], valor);
            break;
        }
    }
}

void TransferenciaContaBanco(tBanco *banco)
{
    int origem, destino, cO, cD;
    float valor;
    cO = cD = -1;
    scanf("%d %d %f\n", &destino, &origem, &valor);
    for (int i = 0; i < banco->qtdContas; i++)
    {
        if (VerificaConta(banco->contas[i], destino))
            cD = i;
        if (VerificaConta(banco->contas[i], origem))
            cO = i;
        if (cO != -1 && cD != -1)
        {
            TransferenciaConta(banco->contas[cD], banco->contas[cO], valor);
            break;
        }
    }
}

void ImprimeRelatorioBanco(tBanco *banco)
{
    printf("===| Imprimindo Relatorio |===\n");
    for (int i = 0; i < banco->qtdContas; i++)
    {
        ImprimeConta(banco->contas[i]);
        printf("\n");
    }
}

void DestroiBanco(tBanco *banco)
{
    int c;

    if (banco != NULL)
    {
        if ((*banco).contas != NULL)
        {
            for (c = 0; c < (*banco).qtdContas; c++)
            {
                DestroiConta((*banco).contas[c]);
            }
            free((*banco).contas);
            banco->contas = NULL;
        }
        free(banco);
        banco = NULL;
    }
}
