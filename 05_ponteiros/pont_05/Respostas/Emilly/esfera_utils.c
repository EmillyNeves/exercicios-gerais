#include <stdio.h>
#include "esfera_utils.h"
#include <math.h>

void CalculaVolume(float R, float *volume)
{
    *volume = (4.0 / 3) * pow(R, 3) * PI;
}

void CalculaArea(float R, float *area){
    *area = 4* pow(R, 2)*PI;
}