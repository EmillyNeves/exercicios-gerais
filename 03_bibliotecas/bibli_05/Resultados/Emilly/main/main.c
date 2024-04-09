#include <stdio.h>
#include "string_utils.h"
int main()
{
    int option, i = 0, tam;
    char string[1000];
    char copia[1000], c;
    while (1)
    {
        scanf("%c", &c);
        printf("%c-", c);
        string[i] = c;
        if (c == '\n')
            break;
        i++;
    }
    while (1)
    {
        printf("1 - Tamanho da string\n");
        printf("2 - Copiar string\n");
        printf("3 - Converter string para letras maiusculas\n");
        printf("4 - Converter string para letras minusculas\n");
        printf("5 - Imprimir string ao contrario\n");
        printf("6 - Encerrar o programa\n");
        printf("Opcao escolhida: \n");
        scanf("%d", &option);

        if (option == 6)
            break;
        else if (option == 1)
        {
            tam = string_length(string);
            printf("Tamanho da string: %d\n", tam-2);
        }
        else if (option == 2)
        {

            string_copy(string, copia);
            printf("String copiada: %s\n", copia);
        }
        else if (option == 3)
        {
            string_upper(string);
            printf("String convertida para maiusculas: %s\n", string);
        }
        else if (option == 4)
        {
            string_lower(string);
            printf("String convertida para minusculas: %s\n", string);
        }
        else if (option == 5)
        {
            string_reverse(string);
            printf("String invertida: %s\n", string);
        }
        printf("\n");
    }

    return 0;
}