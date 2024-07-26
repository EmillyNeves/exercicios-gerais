#include <stdio.h>
#include "calculadora.h"

float Calcular(float num1, float num2, CalculatoraCallback operacao)
{
    return operacao(num1, num2);
}
