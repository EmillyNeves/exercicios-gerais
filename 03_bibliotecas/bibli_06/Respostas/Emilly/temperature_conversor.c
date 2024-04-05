#include<stdio.h>
#include"temperature_conversor.h"
float convert_celsius_to_kelvin(float temperature)
{
    return temperature + 273.15;
}

float convert_celsius_to_fahrenheit(float temperature)
{
    return (temperature * 1.8) + 32;
}

float convert_kelvin_to_celsius(float temperature)
{
    return temperature - 273.15;
}

float convert_kelvin_to_fahrenheit(float temperature)
{
    return (convert_celsius_to_fahrenheit(convert_kelvin_to_celsius(temperature)));
}
float convert_fahrenheit_to_celsius(float temperature)
{
    return (temperature - 32) / 1.8;
}
float convert_fahrenheit_to_kelvin(float temperature)
{
    return convert_celsius_to_kelvin(convert_fahrenheit_to_celsius(temperature));
}

float convert_temperature(float temperature, float convert_func(float temperature))
{
    return convert_func(temperature);
}