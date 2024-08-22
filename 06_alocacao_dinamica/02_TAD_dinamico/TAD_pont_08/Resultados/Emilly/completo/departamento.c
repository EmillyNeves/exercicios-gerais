#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "departamento.h"

tDepartamento *CriaDepartamento()
{
    tDepartamento *dep = (tDepartamento *)malloc(sizeof(tDepartamento));
    dep->c1 = dep->c2 = dep->c3 = dep->diretor = dep->nome = NULL;
    dep->m1 = dep->m2 = dep->m3 = dep->media_geral = -1;

    return dep;
}

void PreencheDadosDepartamento(tDepartamento *depto, char *c1, char *c2, char *c3, char *nome, int m1, int m2, int m3, char *diretor)
{
    depto->m1 = m1;
    depto->m2 = m2;
    depto->m3 = m3;
    depto->media_geral = CalculaMediaGeralDepartamento(depto);
    
    depto->diretor = (char *)malloc(STRING_MAX * sizeof(char));
    strcpy(depto->diretor, diretor);

    depto->nome = (char *)malloc(STRING_MAX * sizeof(char));
    strcpy(depto->nome, nome);

    depto->c1 = (char *)malloc(STRING_MAX * sizeof(char));
    strcpy(depto->c1, c1);

    depto->c2 = (char *)malloc(STRING_MAX * sizeof(char));
    strcpy(depto->c2, c2);

    depto->c3 = (char *)malloc(STRING_MAX * sizeof(char));
    strcpy(depto->c3, c3);

}
void LiberaMemoriaDepartamento(tDepartamento *depto)
{
    free(depto->diretor);
    free(depto->nome);
    free(depto->c1);
    free(depto->c2);
    free(depto->c3);
    free(depto);
}

void ImprimeAtributosDepartamento(tDepartamento *depto)
{
    printf("ATRIBUTOS:\n");
    printf("departamento => %s\n", depto->nome);
    printf("diretor => %s\n", depto->diretor);
    printf("curso1 => %s, media1 => %d\n", depto->c1, depto->m1);
    printf("curso2 => %s, media2 => %d\n", depto->c2, depto->m2);
    printf("curso3 => %s, media3 => %d\n", depto->c3, depto->m3);
    printf("media geral => %.2f\n", depto->media_geral);
    printf("desvio padrao => %.2f\n\n", CalculaDesvioPadraoDepartamento(depto));
}

int ValidaMediaDepartamento(int media)
{
    return media >= 0 && media <= 10;
}

double CalculaDesvioPadraoDepartamento(tDepartamento *depto)
{
    double desvio = 0;
    desvio = (pow((depto->m1 - depto->media_geral), 2) + pow((depto->m2 - depto->media_geral), 2) + pow((depto->m3 - depto->media_geral), 2)) / 3.0;
    return sqrt(desvio);
}

double CalculaMediaGeralDepartamento(tDepartamento *depto)
{
    return (depto->m1 + depto->m2 + depto->m3) / 3.0;
}

void OrdenaPorMediaDepartamentos(tDepartamento *d[], int tamanho)
{
    tDepartamento *aux;
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = i + 1; j < tamanho; j++)
        {
            if (d[j]->media_geral > d[i]->media_geral)
            {
                aux = d[j];
                d[j] = d[i];
                d[i] = aux;
            }
        }
    }
}
