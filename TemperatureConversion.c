#include "TemperatureConversion.h"

//Fahrenheit to Celcius
Celcius FToC(Fahrenheit toConvert){
	return ((toConvert -32) *5/9);
}
//Kelvin to Celcius
Celcius KToC(Kelvin toConvert){
	return (toConvert -273.15);
}
//Celcius to Kelvin
Kelvin CToK(Celcius toConvert){
	return (toConvert + 273.15);
}
//Celcius to Fahrenheit
Fahrenheit CToF(Celcius toConvert){
	return ((toConvert * 9/5) + 32);
}
void fromCelcius(Celcius temperature){
	printf("%.2f celcius sama dengan %.2f fahrenheit\n",temperature,CToF(temperature));
	printf("%.2f celcius sama dengan %.2f kelvin\n",temperature,CToK(temperature));
}
void fromKelvin(Kelvin temperature){
	printf("%.2f kelvin sama dengan %.2f celcius\n",temperature,KToC(temperature));
	printf("%.2f kelvin sama dengan %.2f celcius\n",temperature,CToF(KToC(temperature)));
}
void fromFahrenheit(Fahrenheit temperature){
	printf("%.2f fahrenheit sama dengan %.2f celcius\n",temperature,FToC(temperature));
	printf("%.2f fahrenheit sama dengan %.2f celcius\n",temperature,CToK(FToC(temperature)));
}
