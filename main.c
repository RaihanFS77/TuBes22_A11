#include <stdio.h>
#include <stdlib.h>

#include "Calculator.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

	Calculator kalkulator;

	titleScreen();
	

	menu:
	system("cls");

	int pilihan = optMenu();
	switch(pilihan){
		case 1:
			printf("1");
			calcOpt();
			goto menu;

		case 2:
			printf("2");

			break;

		case 3:
			printf("3");
			howTo();
			goto menu;

		case 4:
			printf("4");
			readHistory();
			getch();
			goto menu;

		case 5:
			printf("\n\n Selamat Tinggal !");
			return;

		default :
			goto menu;

	}
	
}
