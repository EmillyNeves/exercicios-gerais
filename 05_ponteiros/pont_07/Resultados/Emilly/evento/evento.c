#include <stdio.h>
#include "evento.h"

void cadastrarEvento(Evento *eventos, int *numEventos)
{
    scanf("%s", eventos[*numEventos].nome);
    scanf("%d %d %d", &eventos[*numEventos].dia, &eventos[*numEventos].mes, &eventos[*numEventos].ano);
    *numEventos += 1;
}

void exibirEventos(Evento *eventos, int *numEventos)
{
    for (int i = 0; i < *numEventos; i++)
    {
        printf("%d - %s - %02d/%02d/%04d\n", i, eventos[i].nome, eventos[i].dia, eventos[i].mes, eventos[i].ano);
    }
}

void trocarDataEvento(Evento *eventos, int *numEventos)
{
    int indice, ano, dia, mes;
    scanf("%d", &indice);
    scanf("%d %d %d", &dia, &mes, &ano);

    if (indice < 0 || indice > *numEventos)
    {
        printf("Indice invalido!\n");
    }
    else
    {
        eventos[indice].ano = ano;
        eventos[indice].mes = mes;
        eventos[indice].dia = dia;
    }
}
void trocarIndicesEventos(Evento *eventos, int *indiceA, int *indiceB, int *numEventos)
{
    if (indiceA < 0 || indiceA > *numEventos || indiceB < 0 || indiceB > *numEventos)
    {
        printf("Indices invalidos!\n");
    }
    else
    {
        Evento ev = eventos[*indiceA];
        eventos[*indiceA] = eventos[*indiceB];
        eventos[*indiceB] = ev;
    }
}