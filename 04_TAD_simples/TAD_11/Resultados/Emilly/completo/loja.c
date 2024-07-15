#include <stdio.h>
#include "vendedor.h"
#include "loja.h"

tLoja AbreLoja(int id, float aluguel)
{
    tLoja loja;
    loja.id = id;
    loja.totalVendedores = 0;
    loja.lucro = 0;
    loja.aluguel = aluguel;
    return loja;
}

int VerificaIdLoja(tLoja loja, int id)
{
    return (loja.id == id);
}

tLoja ContrataVendedor(tLoja loja, tVendedor vendedor)
{
    int i = loja.totalVendedores;

    loja.vendedores[i] = vendedor;
    loja.totalVendedores++;

    return loja;
}

tLoja RegistraVenda(tLoja loja, char nome[50], float valor)
{

    for (int i = 0; i < loja.totalVendedores; i++)
    {

        if (VerificaNomeVendedor(loja.vendedores[i], nome))
        {
            loja.vendedores[i] = ContabilizaVenda(loja.vendedores[i], valor);
            break;
        }
    }
    return loja;
}

tLoja CalculaLucro(tLoja loja)
{
    float dispesas, receitas;
    dispesas = receitas = 0;
    for (int i = 0; i < loja.totalVendedores; i++)
    {
        dispesas += GetTotalRecebido(loja.vendedores[i]);
        receitas += GetTotalVendido(loja.vendedores[i]);
    }
    dispesas += loja.aluguel;
    loja.lucro = receitas - dispesas;
    return loja;
}

void ImprimeRelatorioLoja(tLoja loja)
{
    printf("Loja %d: Lucro total: R$ %.2f\n", loja.id, loja.lucro);
    for (int i = 0; i < loja.totalVendedores; i++)
    {
        ImprimeRelatorioVendedor(loja.vendedores[i]);
    }
}
