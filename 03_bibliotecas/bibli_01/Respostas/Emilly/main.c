#include <stdio.h>
#include "esfera_utils.h"
int main()
{
    float R;
    scanf("%f", &R);
    printf("Area: %.2f\n", calcula_area(R));
    printf("Volume: %.2f\n",calcula_volume(R));

    return 0;
}