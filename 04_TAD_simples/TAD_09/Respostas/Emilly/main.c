#include <stdio.h>
#include "funcionario.h"
#include "empresa.h"
int main()
{
    int qtdEmp;
    scanf("%d", &qtdEmp);
    tEmpresa empresas[qtdEmp];

    for (int i = 0; i < qtdEmp; i++)
    {
        empresas[i] = leEmpresa();
    }
    for (int i = 0; i < qtdEmp; i++)
    {
        imprimeEmpresa(empresas[i]);
    }

    return 0;
}