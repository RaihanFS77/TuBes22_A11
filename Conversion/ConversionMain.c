#include <stdio.h>
#include <stdlib.h>
#include "MassConversion.h"
#include "TemperatureConversion.h"
#include "TimeConversion.h"

int main(int argc, char *argv[]) {
	int choice;
	startingPoint:
	printf("1. Konversi berat\n");
	printf("2. konversi suhu\n");
	printf("3. konversi waktu\n");
	printf("masukkan pilihan anda : ");
	scanf("%d",&choice);
	switch(choice){
		case 1 : massConvMain();break;
		case 2 : temperatureConvMain();break;
		case 3 : timeConvMain();break;
		default : printf("pilihan tersebut tidak ada\n");goto startingPoint;break;
	}	
}
