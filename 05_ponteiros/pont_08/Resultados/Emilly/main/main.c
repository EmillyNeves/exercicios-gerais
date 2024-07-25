#include <stdio.h>
#include "tDepartamento.h"
int main()
{
    int qtdD;
    scanf("%d\n", &qtdD);
    tDepartamento depto[qtdD];

    for (int i = 0; i < qtdD; i++)
    {
        char curso1[STRING_MAX], curso2[STRING_MAX], curso3[STRING_MAX], diretor[STRING_MAX], nome[STRING_MAX];
        int m1, m2, m3;
        scanf("%[^\n]\n", nome);
        scanf("%[^\n]\n", diretor);
        scanf("%[^\n]\n", curso1);
        scanf("%[^\n]\n", curso2);
        scanf("%[^\n]\n", curso3);
        scanf("%d %d %d\n", &m1, &m2, &m3);

        if (m1 < 0 && m2 < 0 && m3 < 0)
        {
            printf("\nDigite um departamento com médias válidas");
            i--;
            continue;
        }

        depto[i] = CriaDepartamento(curso1, curso2, curso3, nome, m1, m2, m3, diretor);
    }

    OrdenaDepartamentosPorMedia(depto, qtdD);

    for (int i = 0; i < qtdD; i++)
    {
        ImprimeAtributosDepartamento(depto[i]);
    }

    return 0;
}