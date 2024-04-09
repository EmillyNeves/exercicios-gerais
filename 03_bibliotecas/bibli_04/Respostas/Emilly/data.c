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

int calculaDiferencaDias(int dia1, int mes1, int ano1, int dia2, int mes2, int ano2){
    int resp, difano, difmes, difdia, dias=0, i, j;
    resp = comparaData(dia1, mes1, ano1, dia2, mes2, ano2);
    if(resp == 0){
    	return 0;
    }
    if(resp == 1){
    	difano = ano1-ano2;
    	if(difano == 0){
    	    difmes = mes1-mes2;
    	    if(difmes == 0){
    	    	difdia = dia1 - dia2;
    	    	dias = difdia;
    	    }
    	    else{
    	    	dias = dia1;
    	    	difdia = numeroDiasMes(mes2, ano2) - dia2;
    	    	dias += difdia;
    	    	for(i=mes2+1; i<mes1; i++){
    	    	    dias += numeroDiasMes(i, ano2);
    	    	}
    	    }
    	}
    	else{
    	    for(j=ano2; j<ano1; j++){
    	    	for(i=1; i<=12; i++){
    	    	    dias += numeroDiasMes(i, j);
    	    	}
    	    }
    	    difdia = calculaDiasAteMes(mes1, ano1);
    	    dias += difdia;
    	    dias += dia1;
    	    difdia = calculaDiasAteMes(mes2, ano2);
    	    dias -= difdia;
    	    dias -= dia2;
    	}
    }
    else if(resp == -1){
    	difano = ano2-ano1;
    	if(difano == 0){
    	    difmes = mes2-mes1;
    	    if(difmes == 0){
    	    	difdia = dia2 - dia1;
    	    	dias = difdia;
    	    }
    	    else{
    	    	dias = dia2;
    	    	difdia = numeroDiasMes(mes1, ano1) - dia1;
    	    	dias += difdia;
    	    	for(i=mes1+1; i<mes2; i++){
    	    	    dias += numeroDiasMes(i, ano1);
    	    	}
    	    }
    	}
    	else{
    	    for(j=ano1; j<ano2; j++){
    	    	for(i=1; i<=12; i++){
    	    	    dias += numeroDiasMes(i, j);
    	    	}
    	    }
    	    difdia = calculaDiasAteMes(mes2, ano2);
    	    dias += difdia;
    	    dias += dia2;
    	    difdia = calculaDiasAteMes(mes1, ano1);
    	    dias -= difdia;
    	    dias -= dia1;
    	}
    }
    return dias;
}
void imprimeProximaData(int dia, int mes, int ano){

    if(dia+1>numeroDiasMes(mes, ano)){
        dia = 1;
        if(mes == 12){
            mes = 1;
            ano++;
        }
        else{
            mes++;
        }
    }
    else{
    	dia++;
    }
    printf("%02d/%02d/%04d", dia, mes, ano);    
}