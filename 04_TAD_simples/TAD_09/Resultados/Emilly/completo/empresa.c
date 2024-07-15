#include "funcionario.h"
#include "empresa.h"
#include <stdio.h>

tEmpresa criaEmpresa(int id)
{
    tEmpresa empresa;
    empresa.id = id;
    empresa.qtdFuncionarios = 0;

    return empresa;
}

tEmpresa leEmpresa()
{
    int id, qtd;
    scanf("%d %d", &id, &qtd);
    tEmpresa empresa;
    empresa = criaEmpresa(id);

    for (int i = 0; i < qtd; i++)
    {
        tFuncionario func = leFuncionario();
        int flag = 0;
        for (int j = 0; j < i; j++)
        {
            if (getIdFuncionario(empresa.funcionarios[j]) == getIdFuncionario(func))
            {
                printf("A empresa %d ja possui um funcionario com o id %d\n", empresa.id, func.id);
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            empresa = contrataFuncionarioEmpresa(empresa, func);
    }
    return empresa;
}

tEmpresa contrataFuncionarioEmpresa(tEmpresa empresa, tFuncionario funcionario)
{
    int i = 0;
    for (; i < empresa.qtdFuncionarios; i++)
    {
        if (getIdFuncionario(empresa.funcionarios[i]) == -1)
        {
            break;
        }
    }
    empresa.funcionarios[i] = funcionario;
    empresa.qtdFuncionarios++;

    return empresa;
}

void imprimeEmpresa(tEmpresa empresa)
{
    printf("Empresa %d:\n", empresa.id);
    for (int i = 0; i < empresa.qtdFuncionarios; i++)
    {
        imprimeFuncionario(empresa.funcionarios[i]);
    }
    printf("\n");
}
