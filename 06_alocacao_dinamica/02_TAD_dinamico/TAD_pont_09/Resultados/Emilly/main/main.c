#include <stdio.h>
#include "empresa.h"
int main()
{
    int qtdEmp;
    scanf("%d\n", &qtdEmp);
    tEmpresa *empresas[qtdEmp];

    for (int i = 0; i < qtdEmp; i++)
    {
        empresas[i] = CriaEmpresa();
        LeEmpresa(empresas[i]);
    }

    for (int i = 0; i < qtdEmp; i++)
    {
        ImprimeEmpresa(empresas[i]);
        ApagaEmpresa(empresas[i]);
    }

    return 0;
}