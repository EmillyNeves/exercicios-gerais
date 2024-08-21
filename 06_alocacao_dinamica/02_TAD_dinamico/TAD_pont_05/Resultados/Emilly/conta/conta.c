#include <stdlib.h>
#include <stdio.h>
#include "conta.h"
#include "usuario.h"

tConta *CriaConta()
{
    tConta *conta = (tConta *)calloc(1, sizeof(tConta));
    if (conta == NULL)
        exit(1);
    conta->numero = conta->saldo = 0;
    conta->user = NULL;

    return conta;
}

void DestroiConta(tConta *conta)
{
    if (conta == NULL)
        exit(1);
    DestroiUsuario(conta->user);
    free(conta);
}

void LeConta(tConta *conta)
{
    conta->user = CriaUsuario();
    LeUsuario(conta->user);
    scanf("%d\n", &conta->numero);
}

void ImprimeConta(tConta *conta)
{
    printf("Conta: %d\n", conta->numero);
    printf("Saldo: R$ %.2f\n", conta->saldo);
    ImprimeUsuario(conta->user);
}

int VerificaConta(tConta *conta, int numero)
{
    return conta->numero == numero;
}

void SaqueConta(tConta *conta, float valor)
{
    if (conta->saldo >= valor)
    {
        conta->saldo -= valor;
    }
}

void DepositoConta(tConta *conta, float valor)
{
    conta->saldo += valor;
}

void TransferenciaConta(tConta *destino, tConta *origem, float valor)
{
    if (origem->saldo >= valor)
    {
        SaqueConta(origem, valor);
        DepositoConta(destino, valor);
    }
}