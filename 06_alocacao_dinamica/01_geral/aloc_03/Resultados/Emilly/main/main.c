#include <stdio.h>
#include "utils_char.h"
int main()
{
    int tam;
    scanf("%d\n", &tam);

    char *vet = CriaVetor(tam);
    ImprimeString( vet,  tam);
    LeVetor(vet,  tam);
    ImprimeString( vet,  tam);
    
    LiberaVetor(vet);

    return 0;
}