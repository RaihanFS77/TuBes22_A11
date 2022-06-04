#include <stdio.h>
#include <stdlib.h>
#include "MassConversion.h"
#include "TemperatureConversion.h"
#include "TimeConversion.h"

int calcConv() {
	system("cls");
	int choice;
	startingPoint:
	printf("\n\n\n\n");
	printf("\t\t[1] Konversi berat\n");
	printf("\t\t[2] konversi suhu\n");
	printf("\t\t[3] konversi waktu\n");
	printf("\t\tMasukkan pilihan anda : ");
	scanf("%d",&choice);
	switch(choice){
		case 1 : 
			system("cls");
			massConvMain();break;
		case 2 : 
			system("cls");
			temperatureConvMain();break;
		case 3 : 
			system("cls");
			timeConvMain();break;
		default : printf("pilihan tersebut tidak ada\n");goto startingPoint;break;
	}	
}
