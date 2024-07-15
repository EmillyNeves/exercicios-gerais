#include <stdio.h>
#include "departamento.h"
int main()
{
    int qtdDep, m1, m2, m3;
    char nome[STRING_MAX];
    char diretor[STRING_MAX];
    char c1[STRING_MAX], c2[STRING_MAX], c3[STRING_MAX];

    scanf("%d\n", &qtdDep);
    tDepartamento departamentos[qtdDep];

    for (int i = 0; i < qtdDep; i++)
    {
        scanf("%s\n", nome);
        scanf("%s\n", diretor);
        scanf("%s\n", c1);
        scanf("%s\n", c2);
        scanf("%s\n", c3);
        scanf("%d %d %d\n", &m1, &m2, &m3);

        if (validaMediaDepartamento(m1) && validaMediaDepartamento(m2) && validaMediaDepartamento(m3))
            departamentos[i] = criaDepartamento(c1, c2, c3, nome, m1, m2, m3, diretor);
    }

    ordenaPorMediaDepartamentos(departamentos, qtdDep);

    for (int i = 0; i < qtdDep; i++)
        imprimeAtributosDepartamento(departamentos[i]);

    return 0;
}