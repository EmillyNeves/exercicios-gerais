#include <stdio.h>
#include "data.h"

typedef struct
{
    int dia;
    int mes;
    int ano;
} tData;
tData LeData(tData data)
{
    scanf("%d/%d/%d", &data.dia, &data.mes, &data.ano);
    return data;
}
int main()
{
    tData data1, data2;
    data1 = LeData(data1);
    data2 = LeData(data2);

    if (!verificaDataValida(data1.dia, data1.mes, data1.ano) || !verificaDataValida(data2.dia, data2.mes, data2.ano))
        printf("A primeira e/ou segunda data(s) invalida(s)\n");
    else
    {
        printf("Primeira data: ");
        imprimeDataExtenso(data1.dia, data1.mes, data1.ano);
        printf("Segunda data: ");
        imprimeDataExtenso(data2.dia, data2.mes, data2.ano);

        if (comparaData(data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano)==-1)
            printf("A primeira data eh mais antiga\n");
        else if (comparaData(data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano) == 1)
            printf("A segunda data eh mais antiga\n");
        else
            printf("As datas sao iguais\n");
        printf("A diferenca em dias entre as datas eh: %02d dias\n", calculaDiferencaDias(data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano));
    }

    return 0;
}