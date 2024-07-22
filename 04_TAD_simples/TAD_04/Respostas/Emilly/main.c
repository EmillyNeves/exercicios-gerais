#include <stdio.h>
#include "aluno.h"
int main()
{
    int qtdAlunos;
    scanf("%d\n", &qtdAlunos);

    tAluno alunos[qtdAlunos];

    for (int i = 0; i < qtdAlunos; i++)
    {
        alunos[i] = LeAluno();
    }

    for (int i = 0; i < qtdAlunos; i++)
    {
        for (int j = 0; j < qtdAlunos; j++)
        {
            if (ComparaMatricula(alunos[i], alunos[j]) == -1)
            {
                tAluno aux = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = aux;
            }
        }
    }

    for (int i = 0; i < qtdAlunos; i++)
    {
        if(VerificaAprovacao(alunos[i])==1)
        ImprimeAluno(alunos[i]);
    }
    

    return 0;
}