#include <stdio.h>
#include "utils.h"
#include <stdlib.h>
int main()
{
    int tam;
    scanf("%d\n", &tam);
    int *vet = CriaVetor(tam);

    LeVetor(vet, tam);

    printf("%.2f\n", CalculaMedia(vet,tam));
    
    LiberaVetor(vet);
    return 0;
}