#include <stdio.h>
#include "data.h"

void InicializaDataParam(int dia, int mes, int ano, tData *data)
{
    data->ano = ano;
    data->dia = dia;
    data->mes = mes;
    if (data->dia > InformaQtdDiasNoMes(data))
        data->dia = InformaQtdDiasNoMes(data);

    if (data->mes > 12)
        data->mes = 12;

    if (data->mes < 1)
        data->mes = 1;
    if (data->dia < 1)
        data->dia = 1;
}
void LeData(tData *data)
{
    int dia, ano, mes;

    scanf("%d %d %d", &dia, &mes, &ano);
    InicializaDataParam(dia, mes, ano, data);
}
void ImprimeData(tData *data)
{
    printf("'%02d/%02d/%04d'", data->dia, data->mes, data->ano);
}
int EhBissexto(tData *data)
{
    return (data->ano % 4 == 0 && data->ano % 100 == 0) || (data->ano % 400 == 0);
}
int InformaQtdDiasNoMes(tData *data)
{
    if (data->mes == 4 || data->mes == 6 || data->mes == 9 || data->mes == 11)
        return 30;

    else if (data->mes == 2)
    {
        if (EhBissexto(data))
            return 29;
        else
            return 28;
    }
    return 31;
}
void AvancaParaDiaSeguinte(tData *data)
{
    data->dia += 1;
    if (data->dia > InformaQtdDiasNoMes(data))
    {
        data->dia = 1;
        data->mes++;
        if (data->mes > 12)
        {
            data->mes = 1;
            data->ano++;
        }
    }
}
int EhIgual(tData *data1, tData *data2)
{
    return (data1->dia == data2->dia) && (data1->mes == data2->mes) && (data1->ano == data2->ano);
}