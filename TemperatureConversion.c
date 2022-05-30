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
	celciusToFahrenheit(temperature);
	celciusToKelvin(temperature);
}
void fromKelvin(Kelvin temperature){
	KelvinToCelcius(temperature);
	KelvinToFahrenheit(temperature);
}
void fromFahrenheit(Fahrenheit temperature){
	fahrenheitToCelcius(temperature);
	fahrenheitToKelvin(temperature);
}
void celciusToFahrenheit(Celcius toConvert){
	printf("%.2f celcius sama dengan %.2f fahrenheit\n",toConvert,CToF(toConvert));
}
void celciusToKelvin(Celcius toConvert){
	printf("%.2f celcius sama dengan %.2f kelvin\n",toConvert,CToK(toConvert));
}
void fahrenheitToCelcius(Fahrenheit toConvert){
	printf("%.2f fahrenheit sama dengan %.2f celcius\n",toConvert,FToC(toConvert));
}
void fahrenheitToKelvin(Fahrenheit toConvert){
	printf("%.2f fahrenheit sama dengan %.2f celcius\n",toConvert,CToK(FToC(toConvert)));
}
void KelvinToCelcius(Kelvin toConvert){
	printf("%.2f kelvin sama dengan %.2f celcius\n",toConvert,KToC(toConvert));
}
void KelvinToFahrenheit(Kelvin toConvert){
	printf("%.2f kelvin sama dengan %.2f celcius\n",toConvert,CToF(KToC(toConvert)));
}
