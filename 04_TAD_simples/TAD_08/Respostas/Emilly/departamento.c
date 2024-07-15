#include <stdio.h>
#include <math.h>
#include "departamento.h"
#include <string.h>

tDepartamento criaDepartamento(char *c1, char *c2, char *c3, char *nome, int m1, int m2, int m3, char *diretor)
{
    tDepartamento departamento;

    strcpy(departamento.c1, c1);
    strcpy(departamento.c2, c2);
    strcpy(departamento.c3, c3);
    strcpy(departamento.nome, nome);
    strcpy(departamento.diretor, diretor);
    departamento.m1 = m1;
    departamento.m2 = m2;
    departamento.m3 = m3;
    departamento.media_geral = calculaMediaGeralDepartamento(departamento);

    return departamento;
}

void imprimeAtributosDepartamento(tDepartamento depto)
{

    printf("ATRIBUTOS:\n");
    printf("departamento => %s\n", depto.nome);
    printf("diretor => %s\n", depto.diretor);
    printf("curso1 => %s, media1 => %d\n", depto.c1, depto.m1);
    printf("curso2 => %s, media2 => %d\n", depto.c2, depto.m2);
    printf("curso3 => %s, media3 => %d\n", depto.c3, depto.m3);
    printf("media geral => %.2f\n", depto.media_geral);
    printf("desvio padrao => %.2f\n\n", calculaDesvioPadraoDepartamento(depto));
}

int validaMediaDepartamento(int media)
{
    return media >= 0 && media <= 10;
}

double calculaDesvioPadraoDepartamento(tDepartamento depto)
{
    double desvio = 0, media = calculaMediaGeralDepartamento(depto);

    desvio = ((pow((depto.m1 - media), 2) + pow((depto.m2 - media), 2) + pow((depto.m3 - media), 2))) * 1.0;
    desvio = sqrt(desvio / 3.0);

    return desvio;
}

double calculaMediaGeralDepartamento(tDepartamento depto)
{
    return (depto.m1 + depto.m2 + depto.m3) / 3.0;
}

void ordenaPorMediaDepartamentos(tDepartamento d[], int tamanho)
{
    tDepartamento aux;
    float maior = 0;
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho; j++)
        {
            maior = d[i].media_geral;

            if (d[j].media_geral< maior)
            {
                aux = d[j];
                maior = d[j].media_geral;
                d[j] = d[i];
                d[i] = aux;
            }
        }
    }
}
