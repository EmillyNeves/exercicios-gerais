#include <stdio.h>
#include "calculadora.h"
float Add(float n1, float n2)
{
    return n1 + n2;
}
float Sub(float n1, float n2)
{
    return n1 - n2;
}
float Mult(float n1, float n2)
{
    return n1 * n2;
}
float Div(float n1, float n2)
{
    return n1 / n2;
}
int main()
{
    char acao;
    float n1, n2, resultado;
    while (1)
    {
        scanf("%c\n", &acao);
        if (acao == 'f')
            break;

        scanf("%f %f\n", &n1, &n2);

        if (acao == 'a')
        {
            resultado = Calcular(n1, n2, Add);
            printf("%.2f + %.2f = %.2f\n", n1, n2, resultado);
        }
        else if (acao == 's')
        {
            resultado = Calcular(n1, n2, Sub);
            printf("%.2f - %.2f = %.2f\n", n1, n2, resultado);
        }
        else if (acao == 'm')
        {
            resultado = Calcular(n1, n2, Mult);
            printf("%.2f x %.2f = %.2f\n", n1, n2, resultado);
        }
        else if (acao == 'd')
        {
            resultado = Calcular(n1, n2, Div);
            printf("%.2f / %.2f = %.2f\n", n1, n2, resultado);
        }
    }

    return 0;
}