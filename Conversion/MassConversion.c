#include "MassConversion.h"
void massConvMain(){
	int choice;
	startingPoint:
	printf("\n\n\n\n");
	printf("\t\t[1] konversi dari kilogram\n");
	printf("\t\t[2] konversi dari ons\n");
	printf("\t\t[3] konversi dari gram\n");
	printf("\t\tmasukkan pilihan anda : ");
	scanf("%d",&choice);
	switch(choice){
		case 1 : 
		system("cls");
		fromKilo(getMassValueToConv());break;
		case 2 : 
		system("cls");
		fromOns(getMassValueToConv());break;
		case 3 : 
		system("cls");
		fromGram(getMassValueToConv());break;
		default : printf("pilihan tersebut tidak ada\n");goto startingPoint;break;
	}
	printf("\n\t\t[]Tekan tombol apapun untuk kembali[]");
	getch();
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
	printf("\n%.2f kilo sama dengan %.2f ons\n",mass,KiloToOns(mass));
	printf("\n%.2f kilo sama dengan %.2f gram\n",mass,OnsToGram(KiloToOns(mass)));
}
void fromOns(Ons mass){
	printf("\n%.2f ons sama dengan %.2f kilo\n",mass,OnsToKilo(mass));
	printf("\n%.2f ons sama dengan %.2f gram\n",mass,OnsToGram(mass));
}
void fromGram(Gram mass){
	printf("\n%.2f gram sama dengan %.2f ons\n",mass,GramToOns(mass));
	printf("\n%.2f gram sama dengan %.2f kilo\n",mass,OnsToKilo(GramToOns(mass)));
}
