#include "TemperatureConversion.h"
void temperatureConvMain(){
	int choice;
	startingPoint:
	printf("\n\n\n\n");
	printf("\t\t[1] konversi dari celcius ke fahrenheit dan kelvin\n");
	printf("\t\t[2] konversi dari fahrenheit ke celcius dan kelvin\n");
	printf("\t\t[3] konversi dari kelvin ke celcius dan fahrenheit\n");
	printf("\t\tMasukkan pilihan anda : ");
	scanf("%d",&choice);
	switch(choice){
		case 1 : 
		system("cls");
		fromCelcius(getTemperatureValueToConv());break;
		case 2 : 
		system("cls");
		fromFahrenheit(getTemperatureValueToConv());break;
		case 3 : 
		system("cls");
		fromKelvin(getTemperatureValueToConv());break;
		default : printf("pilihan tersebut tidak ada\n");goto startingPoint;break;
	}
	printf("\n\t\t[]Tekan tombol apapun untuk kembali[]");
	getch();
}
float getTemperatureValueToConv(){
	float value;
	printf("masukkan angka yang akan dikonversi : ");
	scanf("%f",&value);
	return value;
}
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
	printf("\n%.2f celcius sama dengan %.2f Fahrenheit\n",temperature,CToF(temperature));
	printf("\n%.2f celcius sama dengan %.2f Kelvin\n",temperature,CToK(temperature));
}
void fromKelvin(Kelvin temperature){
	printf("\n%.2f kelvin sama dengan %.2f Celcius \n",temperature,KToC(temperature));
	printf("\n%.2f kelvin sama dengan %.2f Fahrenheit\n",temperature,CToF(KToC(temperature)));
}
void fromFahrenheit(Fahrenheit temperature){
	printf("\n%.2f fahrenheit sama dengan %.2f Celcius\n",temperature,FToC(temperature));
	printf("\n%.2f fahrenheit sama dengan %.2f Kelvin\n",temperature,CToK(FToC(temperature)));
}
