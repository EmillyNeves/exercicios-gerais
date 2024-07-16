#include <stdio.h>
#include "conta.h"
int main()
{
    int acao = -1, limteContas;
    scanf("%d", &limteContas);

    tConta contas[limteContas];
    int qtdContas = 0;

    while (1)
    {
        scanf("%d\n", &acao);
        if (acao == 0)
            break;
        else if (acao == 1)
        {
            float valor;
            int numero;
            scanf("%d %f", &numero, &valor);
            for (int i = 0; i < qtdContas; i++)
            {
                if (VerificaConta(contas[i], numero))
                    contas[i] = SaqueConta(contas[i], valor);
            }
        }
        else if (acao == 2)
        {
            float valor;
            int numero;
            scanf("%d %f", &numero, &valor);
            for (int i = 0; i < qtdContas; i++)
            {
                if (VerificaConta(contas[i], numero))
                    contas[i] = DepositoConta(contas[i], valor);
            }
        }
        else if (acao == 3 && qtdContas<limteContas)
        {
            int numero;
            char nome[50], cpf[15];
            tUsuario user;
            scanf("%s %s %d", nome, cpf, &numero);
            user = CriaUsuario(nome, cpf);
            contas[qtdContas] = CriaConta(numero, user);
            qtdContas++;
        }
        else if(acao==4){
            printf("===| Imprimindo Relatorio |===\n");
            for (int i = 0; i < qtdContas; i++)
            {
                ImprimeConta(contas[i]);
            }
        }
    }

    return 0;
}