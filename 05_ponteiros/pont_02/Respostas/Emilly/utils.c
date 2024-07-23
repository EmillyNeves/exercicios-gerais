#include <stdio.h>
#include "utils.h"

void LeIntervalo(int *m, int *n)
{
    scanf("%d %d", m, n);
}

int EhPrimo(int n)
{
    if (n < 2)
        return 0;
    for (int dev = 2; dev < n; dev++)
    {
        if (n % dev == 0)
            return 0;
    }
    return 1;
}

void ObtemMaiorEMenorPrimo(int m, int n, int *menor, int *maior)
{
    *menor = n;
    *maior = m;

    for (int i = m; i <= n; i++)
    {
        if (EhPrimo(i))
        {
            if (*menor > i)
                *menor = i;
            if (*maior < i)
                *maior = i;
        }
    }
}