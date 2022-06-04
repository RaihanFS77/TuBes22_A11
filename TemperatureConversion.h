#include <stdio.h>
#include <string.h>
#ifndef TemperatureConversion_H
#define TemperatureConversion_H
typedef float Celcius;
typedef float Fahrenheit;
typedef float Kelvin;
//Fahrenheit to Celcius
Celcius FToC(Fahrenheit toConvert);
//Kelvin to Celcius
Celcius KToC(Kelvin toConvert);
//Celcius to Kelvin
Kelvin CToK(Celcius toConvert);
//Celcius to Fahrenheit
Fahrenheit CToF(Celcius toConvert);
void fromCelcius(Celcius temperature);
void fromKelvin(Kelvin temperature);
void fromFahrenheit(Fahrenheit temperature);
void celciusToFahrenheit(Celcius toConvert);
void celciusToKelvin(Celcius toConvert);
void fahrenheitToCelcius(Fahrenheit toConvert);
void fahrenheitToKelvin(Fahrenheit toConvert);
void KelvinToCelcius(Kelvin toConvert);
void KelvinToFahrenheit(Kelvin toConvert);
#endif
