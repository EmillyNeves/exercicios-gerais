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
    tData data1;
    data1 = LeData(data1);

    if (!verificaDataValida(data1.dia, data1.mes, data1.ano))
        printf("A data informada eh invalida\n");
    else
    {
        printf("Data informada: ");
        imprimeDataExtenso(data1.dia, data1.mes, data1.ano);

        if (verificaBissexto(data1.ano))
            printf("O ano informado eh bissexto\n");
        else
            printf("O ano informado nao eh bissexto\n");
        printf("O mes informado possui %d dias\n", numeroDiasMes(data1.mes, data1.ano));

        printf("A data seguinte eh: ");
        imprimeProximaData(data1.dia, data1.mes, data1.ano);
    }

    return 0;
}