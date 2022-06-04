#include "MassConversion.h"
void massConvMain(){
	int choice;
	startingPoint:
	printf("1. konversi dari kilogram\n");
	printf("2. konversi dari ons\n");
	printf("3. konversi dari gram\n");
	printf("masukkan pilihan anda : ");
	scanf("%d",&choice);
	switch(choice){
		case 1 : fromKilo(getMassValueToConv());break;
		case 2 : fromOns(getMassValueToConv());break;
		case 3 : fromGram(getMassValueToConv());break;
		default : printf("pilihan tersebut tidak ada\n");goto startingPoint;break;
	}
	
}
float getMassValueToConv(){
	float value;
	printf("masukkan angka yang akan dikonversi : ");
	scanf("%f",&value);
	return value;
}

Ons KiloToOns(Kilo toConvert){
	return toConvert*10;
}
Gram OnsToGram(Ons toConvert){
	return toConvert*10;
}
Ons GramToOns(Gram toConvert){
	return toConvert/10;
}
Kilo OnsToKilo(Ons toConvert){
	return toConvert/10;
}
void fromKilo(Kilo mass){
	printf("%.2f kilo sama dengan %.2f ons\n",mass,KiloToOns(mass));
	printf("%.2f kilo sama dengan %.2f gram\n",mass,OnsToGram(KiloToOns(mass)));
}
void fromOns(Ons mass){
	printf("%.2f ons sama dengan %.2f kilo\n",mass,OnsToKilo(mass));
	printf("%.2f ons sama dengan %.2f gram\n",mass,OnsToGram(mass));
}
void fromGram(Gram mass){
	printf("%.2f gram sama dengan %.2f ons\n",mass,GramToOns(mass));
	printf("%.2f gram sama dengan %.2f kilo\n",mass,OnsToKilo(GramToOns(mass)));
}
