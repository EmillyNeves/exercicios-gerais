#include <stdio.h>
#include "departamento.h"
int main()
{
    int qtd;
    scanf("%d\n", &qtd);
    tDepartamento *dep[qtd];

    for (int i = 0; i < qtd; i++)
    {
        dep[i] = CriaDepartamento();

        if (dep[i] != NULL)
        {
            char c1[STRING_MAX], c2[STRING_MAX], c3[STRING_MAX], diretor[STRING_MAX], nome[STRING_MAX];
            int m1, m2, m3;
            scanf("%s\n", nome);
            scanf("%s\n", diretor);
            scanf("%s\n", c1);
            scanf("%s\n", c2);
            scanf("%s\n", c3);
            scanf("%d %d %d\n", &m1, &m2, &m3);
            PreencheDadosDepartamento(dep[i], c1, c2, c3, nome, m1, m2, m3, diretor);
        }
    }

    OrdenaPorMediaDepartamentos(dep, qtd);

    for (int i = 0; i < qtd; i++)
    {
        if (ValidaMediaDepartamento(dep[i]->media_geral))
            ImprimeAtributosDepartamento(dep[i]);
        LiberaMemoriaDepartamento(dep[i]);
    }

    return 0;
}