#include <stdio.h>
#include <string.h>
#include "tDepartamento.h"

tDepartamento CriaDepartamento(char *curso1, char *curso2, char *curso3,
                               char *nome, int m1, int m2, int m3, char *diretor)
{
    tDepartamento dep;
    strcpy(dep.curso1, curso1);
    strcpy(dep.curso2, curso2);
    strcpy(dep.curso3, curso3);
    strcpy(dep.diretor, diretor);
    strcpy(dep.nome, nome);
    if (m1 < 0)
        m1 *= -1;
    if (m2 < 0)
        m2 *= -1;
    if (m3 < 0)
        m3 *= -1;
    dep.m1 = m1;
    dep.m2 = m2;
    dep.m3 = m3;

    return dep;
}

void ImprimeAtributosDepartamento(tDepartamento depto)
{
    float media = (float)(depto.m1 + depto.m2 + depto.m3) / 3;
    printf("\nDepartamento: %s\n", depto.nome);
    printf("\tDiretor: %s\n", depto.diretor);
    printf("\t1o curso: %s\n", depto.curso1);
    printf("\tMedia do 1o curso: %d\n", depto.m1);
    printf("\t2o curso: %s\n", depto.curso2);
    printf("\tMedia do 2o curso: %d\n", depto.m2);
    printf("\t3o curso: %s\n", depto.curso3);
    printf("\tMedia do 3o curso: %d\n", depto.m3);
    printf("\tMedia dos cursos:%.2f\n", media);
}
void OrdenaDepartamentosPorMedia(tDepartamento *vetor_deptos, int num_deptos)
{
    for (int i = 0; i < num_deptos; i++)
    {
        float media1 = (float)(vetor_deptos[i].m1 + vetor_deptos[i].m2 + vetor_deptos[i].m3) / 3;
        for (int j = i + 1; j < num_deptos; j++)
        {
            float media2 = (float)(vetor_deptos[j].m1 + vetor_deptos[j].m2 + vetor_deptos[j].m3) / 3;
            if (media1 < media2)
            {
                tDepartamento aux = vetor_deptos[i];
                vetor_deptos[i] = vetor_deptos[j];
                vetor_deptos[i] = aux;
            }
        }
    }
}