#include <stdio.h>
int main()
{
    int numeroAtual = 1, numLinhas;
    scanf("%d", &numLinhas);

    for (int i = 0; i < numLinhas; i++)
    {
        for (int j = 0; j <= i; j++, numeroAtual++)
        {
            printf("%d ", numeroAtual);
        }
        printf("\n");
    }
    return 0;
}