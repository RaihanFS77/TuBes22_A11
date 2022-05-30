#include <stdio.h>
#include <string.h>
#ifndef TemperatureConversion_H
#define TemperatureConversion_H
#define CelcToFahren "CelciusToFahrenheit"
#define CelcToKelv "CelciusToKelvin"
#define FahrenToCelc "FahrenheitToCelcius"
#define FahrenToKelv "FahrenheitToCelcius"
#define KelvToCelc "KelvinToCelcius"
#define KelvToFahren "KelvinToFahrenheit"
typedef struct float Celcius;
typedef struct float Fahrenheit;
typedef struct float Kelvin;
void fromCelcius(Celcius toConvert);
void fromFahrenheit(Fahrenheit toConvert);
void fromKelvin(Kelvin toConvert);
int getConversion(float number, char choice[]);
#endif
