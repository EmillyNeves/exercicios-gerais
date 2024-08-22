#include <stdio.h>
#include <stdlib.h>
#include "funcionario.h"

tFuncionario *CriaFuncionario()
{
    tFuncionario *proletariado = NULL;
    proletariado = (tFuncionario *)malloc(sizeof(tFuncionario));
    proletariado->id = -1;
    proletariado->salario = -1;
    return proletariado;
}

void ApagaFuncionario(tFuncionario *funcionario)
{
    free(funcionario);
}

void LeFuncionario(tFuncionario *funcionario)
{
    scanf("%d %f\n", &funcionario->id, &funcionario->salario);
}

int GetIdFuncionario(tFuncionario *funcionario){
    return funcionario->id;
}

void ImprimeFuncionario(tFuncionario *funcionario){
    printf("- Funcionario %d: RS %.2f\n", funcionario->id, funcionario->salario);
}