#include <stdio.h>
#include "temperature_conversor.h"
int main()
{
    float temp;
    char escala1, escala2;

    scanf("%f %c %c", &temp, &escala1, &escala2);

    if (escala1 == 'f')
    {
        if (escala2 == 'c')
            temp = convert_fahrenheit_to_celsius(temp);

        else if (escala2 == 'k')
            temp = convert_fahrenheit_to_kelvin(temp);
    }
    else if (escala1 == 'c')
    {
        if (escala2 == 'f')
            temp = convert_celsius_to_fahrenheit(temp);
        else if (escala2 == 'k')
            temp = convert_celsius_to_kelvin(temp);
    }
    else if (escala1 == 'k')
    {
        if (escala2 == 'f')
            temp = convert_kelvin_to_fahrenheit(temp);
        else if (escala2 == 'c')
            temp = convert_kelvin_to_celsius(temp);
    }

    printf("Temperature: %.2f%c", temp, escala2 - 32);
    if (escala2 != 'k')
        printf("º");

    return 0;
}