#include <stdio.h>
#include <stdlib.h>
#include "funcionario.h"
#include "empresa.h"

tEmpresa *CriaEmpresa()
{
  tEmpresa *burgues = NULL;
  burgues = (tEmpresa *)malloc(sizeof(tEmpresa));
  burgues->qtdFuncionarios = 0;
  burgues->funcionarios = NULL;
  burgues->id = -1;
  return burgues;
}

void LeEmpresa(tEmpresa *empresa)
{
  int id, qtdCandidatos;
  scanf("%d %d", &id, &qtdCandidatos);
  empresa->id = id;
  empresa->funcionarios = (tFuncionario **)malloc(qtdCandidatos * sizeof(tFuncionario *));

  for (int i = 0; i < qtdCandidatos; i++)
  {
    tFuncionario *func = CriaFuncionario();
    LeFuncionario(func);
    ContrataFuncionarioEmpresa(empresa, func);
  }
  empresa->funcionarios = (tFuncionario **)realloc(empresa->funcionarios, empresa->qtdFuncionarios * sizeof(tFuncionario *));
}

void ApagaEmpresa(tEmpresa *empresa)
{
  for (int i = 0; i < empresa->qtdFuncionarios; i++)
  {
    ApagaFuncionario(empresa->funcionarios[i]);
  }
  free(empresa->funcionarios);
  free(empresa);
}

void ContrataFuncionarioEmpresa(tEmpresa *empresa, tFuncionario *funcionario)
{
  int contratado = 0;
  if (empresa->qtdFuncionarios > 0)
  {
    for (int i = 0; i < empresa->qtdFuncionarios; i++)
    {
      if (GetIdFuncionario(funcionario) == GetIdFuncionario(empresa->funcionarios[i]) && empresa->funcionarios[i] != NULL)
      {
        contratado = 1;
        break;
      }
    }
  }
  if (!contratado)
  {
    empresa->funcionarios[empresa->qtdFuncionarios] = funcionario;
    empresa->qtdFuncionarios++;
  }
  else
  {
    printf("A empresa %d ja possui um funcionario com o id %d\n", empresa->id, funcionario->id);
    ApagaFuncionario(funcionario);
  }
}

void ImprimeEmpresa(tEmpresa *empresa)
{
  printf("Empresa %d:\n", empresa->id);
  for (int i = 0; i < empresa->qtdFuncionarios; i++)
  {
    ImprimeFuncionario(empresa->funcionarios[i]);
  }
}
