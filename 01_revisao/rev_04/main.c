#include <stdio.h>
#include<math.h>
int main()
{
    int numDecimal, resto, aux=0, numOctal=0;
    scanf("%d", &numDecimal);

    while (1)
    {
        resto = numDecimal % 8;
        numDecimal /= 8;
        numOctal = numOctal + pow(10, aux) * resto;
        aux++;
        if (numDecimal < 8)
        {
            numOctal += numDecimal * pow(10, aux);
            break;
        }
    }
        printf("%d", numOctal);

    return 0;
}
