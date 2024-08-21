#include "aluno.h"
#include <stdlib.h>
#include <stdio.h>

tAluno *CriaAluno()
{
    tAluno *aluno = (tAluno *)malloc(sizeof(tAluno));
    aluno->matricula = -1;
    aluno->n1 = aluno->n2 = aluno->n3 = -1;
    aluno->nome = NULL;

    return aluno;
}

void ApagaAluno(tAluno *aluno)
{
    free(aluno->nome);
    free(aluno);
}

void LeAluno(tAluno *aluno)
{
    char c;
    int i = 0;
    while (1)
    {
        scanf("%c", &c);
        aluno->nome = realloc(aluno->nome, i+1 * sizeof(char));
        if (c == '\n')
        {
            aluno->nome[i] = '\0';
            break;
        }
        aluno->nome[i] = c;
        i++;
    }
    scanf("%d\n", &aluno->matricula);
    scanf("%d %d %d\n", &aluno->n1, &aluno->n2, &aluno->n3);
}

int ComparaMatricula(tAluno *aluno1, tAluno *aluno2)
{
    if (aluno1->matricula > aluno2->matricula)
        return 1;
    else if (aluno1->matricula < aluno2->matricula)
        return -1;
    return 0;
}

int CalculaMediaAluno(tAluno *aluno)
{
    return (aluno->n1 + aluno->n2 + aluno->n3) / 3;
}

int VerificaAprovacao(tAluno *aluno)
{
    return CalculaMediaAluno(aluno) >= 7;
}

void ImprimeAluno(tAluno *aluno)
{
    printf("%s\n", aluno->nome);
}