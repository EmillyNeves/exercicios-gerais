#include <stdio.h>
#include "utils_char2.h"
#include <string.h>
int main()
{
    char *vet = CriaVetorTamPadrao();
    int tam = strlen(vet);
    vet = LeVetor(vet, &tam);

    ImprimeString(vet);

    LiberaVetor(vet);

    return 0;
}