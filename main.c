#include <stdio.h>
#include <stdlib.h>
#include "Conversion/ConversionMain.c"
#include "Conversion/MassConversion.c"
#include "Conversion/TemperatureConversion.c"
#include "Conversion/TimeConversion.c"
#include "Calculator.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

	Calculator kalkulator;
	//Menampilkan Splash Screen Logo Inter Alia
	titleScreen();
	

	menu:
	system("cls");

	int pilihan = optMenu();
	switch(pilihan){
		case 1:
		//Kalkulator
			calcOpt();
			goto menu;

		case 2:
		//Konversi Satuan
			calcConv();
			goto menu;
			break;

		case 3:
		//Buka dan menampilkan File How-To
			howTo();
			goto menu;

		case 4:
		//Buka dan menampilkan File History.dat
			readHistory();
			getch();
			goto menu;

		case 5:
		//Quit
			printf("\n\n Selamat Tinggal !");
			return;

		default :
			goto menu;

	}
	
}
