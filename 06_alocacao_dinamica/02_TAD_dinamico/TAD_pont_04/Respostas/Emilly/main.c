#include "aluno.h"
int main()
{
    int qtdAlunos;
    scanf("%d\n", &qtdAlunos);
    tAluno *alunos[qtdAlunos];

    for (int i = 0; i < qtdAlunos; i++)
    {
        alunos[i] = CriaAluno();
    }

    for (int i = 0; i < qtdAlunos; i++)
    {
        LeAluno(alunos[i]);
        if (i > 0)
        {
            for (int j = 0; j <= i; j++)
            {
                tAluno *aux;
                if (ComparaMatricula(alunos[i], alunos[j]) == -1)
                {
                    aux = alunos[i];
                    alunos[i] = alunos[j];
                    alunos[j] = aux;
                }
            }
        }
    }

    for (int i = 0; i < qtdAlunos; i++)
    {
        if (VerificaAprovacao(alunos[i]))
            ImprimeAluno(alunos[i]);
        ApagaAluno(alunos[i]);
    }

    return 0;
}