#include<stdio.h>
#include"string_utils.h"
int string_length(char *str)
{
    int i = 0;
    while (str[i] != "\0")
    {
        i++;
    }
    return i;
}

void string_copy(char *src, char *dest)
{
    for (int i = 0; src[i] != "\0"; i++)
    {
        dest[i] = src[i];
    }
}

void string_upper(char *str)
{
    for (int i = 0; str[i] != "\0"; i++)
    {
        str[i] -= 32;
    }
}

void string_lower(char *str)
{
    for (int i = 0; str[i] != "\0"; i++)
    {
        str[i] += 32;
    }
}

void string_reverse(char *str)
{
    char aux;
    int tam = string_length(str);
    for (int i = 0; i <= tam/2; i++)
    {
        aux = str[i];
        str[tam - i] = aux;
    }
}