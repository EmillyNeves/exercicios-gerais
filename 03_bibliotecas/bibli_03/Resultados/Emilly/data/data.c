#include <stdio.h>
#include "data.h"

int verificaBissexto(int ano)
{
    return (ano % 400 == 0 || (ano % 4 == 0 && ano % 100 != 0));
}


int verificaDataValida(int dia, int mes, int ano)//ok
{
    if (mes < 1 || mes > 12)
        return 0;
    if (dia < 1 || numeroDiasMes(mes, ano) < dia)
        return 0;
    if (ano < 1)
        return 0;
    return 1;
}

void imprimeMesExtenso(int mes)
{
    if (mes == 1)
        printf("Janeiro");
    else if (mes == 2)
        printf("Fevereiro");
    else if (mes == 3)
        printf("Março");
    else if (mes == 4)
        printf("Abril");
    else if (mes == 5)
        printf("Maio");
    else if (mes == 6)
        printf("Junho");
    else if (mes == 7)
        printf("Julho");
    else if (mes == 8)
        printf("Agosto");
    else if (mes == 9)
        printf("Setembro");
    else if (mes == 10)
        printf("Outubro");
    else if (mes == 11)
        printf("Novembro");
    else if (mes == 12)
        printf("Dezembro");
}


void imprimeDataExtenso(int dia, int mes, int ano){
    printf("%02d de ", dia);
    imprimeMesExtenso(mes);
    printf(" de %04d\n", ano);
}

int numeroDiasMes(int mes, int ano)//ok
{
    if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
        return 31;
    else if (mes == 2)
    {
        if (verificaBissexto(ano))
            return 29;
        return 28;
    }
    return 30;
}

int comparaData(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
    if (ano1 == ano2)
    {
        if (mes1 == mes2)
        {
            if (dia1 == dia2)
                return 0;
            if (dia1 > dia2)
                return 1;
        }
        else if (mes1 > mes2)
            return 1;
    }
    else if (ano1 < ano2)
        return -1;
    else if(mes1==mes2){
        if(dia1<dia2)
        return -1;
    }
    return 1;
}

int calculaDiasAteMes(int mes, int ano){
    int dias=0, i;
    for(i=1; i<mes; i++){
        dias += numeroDiasMes(i, ano);
    }
    return dias;
}

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2)
{
    int qtdDias = 0;
    if (comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == -1)
    {
        while (qtdDias != dia2 && mes1 != mes2 && ano1 != ano2)
        {
            dia1++;
            qtdDias++;
            if (dia1 > numeroDiasMes(mes1, ano1))
            {
                dia1 = 1;
                mes1++;
                if (mes1 > 12)
                {
                    mes1 = 1;
                    ano1++;
                }
            }
        }
    }
    else if (comparaData(dia1, mes1, ano1, dia2, mes2, ano2) == 1)
    {
        while (qtdDias != dia2 && mes1 != mes2 && ano1 != ano2)
        {
            dia2++;
            qtdDias++;
            if (dia2 > numeroDiasMes(mes2, ano2))
            {
                dia2 = 1;
                mes2++;
                if (mes2 > 12)
                {
                    mes2 = 1;
                    ano2++;
                }
            }
        }
    }
    return qtdDias;
}