#include <stdio.h>
#include <math.h>
int main()
{
    float raioD, raioA, disparoX, disparoY, alvoX, alvoY, somaRaios = 0, distancia = 0;

    scanf("%f %f %f", &alvoX, &alvoY, &raioA);
    scanf("%f %f %f", &disparoX, &disparoY, &raioD);

    somaRaios = raioA + raioD;
    distancia = sqrt(pow((alvoX - disparoX), 2) + pow((alvoY - disparoY), 2));

    if (somaRaios < distancia)
        printf("ERROU");
    else
        printf("ACERTOU");

    return 0;
}