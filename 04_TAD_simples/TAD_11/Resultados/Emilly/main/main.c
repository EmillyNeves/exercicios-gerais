#include <stdio.h>
#include "loja.h"
int main()
{
    int qtdLojas, acao = -1, lojasCadastradas = 0;
    scanf("%d", &qtdLojas);
    tLoja lojas[qtdLojas];

    while (1)
    {
        scanf("%d\n", &acao);
        
        if (acao == 0)
            break;
        else if (acao == 1)
        {
            int id;
            float aluguel;
            scanf("%d %f\n", &id, &aluguel);
            lojas[lojasCadastradas] = AbreLoja(id, aluguel);
            lojasCadastradas++;
        }
        else if (acao == 2)
        {
            char nome[50];
            int id;
            float salario, comissao;
            scanf("%s %f %f\n%d\n", nome, &salario, &comissao, &id);
            tVendedor vendedor = RegistraVendedor(nome, salario, comissao);
            lojas[id-1] = ContrataVendedor(lojas[id-1], vendedor);
        }
        else if (acao == 3)
        {
            int id;
            char nome[50];
            float valor;
            scanf("%d %s %f\n", &id, nome, &valor);
            lojas[id-1] = RegistraVenda(lojas[id-1], nome, valor);
        }
        else if (acao == 4)
        {
            for (int i = 0; i < lojasCadastradas; i++)
            {
                lojas[i] = CalculaLucro(lojas[i]);
                ImprimeRelatorioLoja(lojas[i]);
            }
        }
    }

    return 0;
}