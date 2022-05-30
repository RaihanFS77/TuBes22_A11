#include <stdio.h>
#include <stdlib.h>

#include "Calculator.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

	Calculator kalkulator;

	
	while(true){
		StartOfCalc:
	system("cls");
		//Inisialisasi Kalkulator
		createCalculator(&kalkulator);

		//Input ekspresi matematika
		insertExpression(&kalkulator);

		//Melakukan reformatting apabila ditemukan kejanggalan
		checkForFormatting(&kalkulator.input);
		printf("%s",kalkulator.input);
		getch();
		
		//Melakukan test validasi ekspresi matematis
		if(!isValidExpression(kalkulator.input)){
			sleep(1);
			goto StartOfCalc;
		}

		

	//Memasukan ekspresi menjadi binary tree
	kalkulator.CalcTree = expressionToTree(kalkulator.input,0,countStringLength(kalkulator.input)-1);

	//Start the calculation process
		bool sukses = true;
		kalkulator.result = startCalculation(kalkulator.CalcTree,&sukses);

	//Print the result
	printResult(kalkulator,sukses);

	//Dealokasi Tree
	deleteTree(kalkulator.CalcTree);

	//Apabila success maka disimpan data nya ke history
	if(sukses){
	saveHistory(kalkulator.input,kalkulator.result);
	}

	if(!stayCalculating()){
		break;
	}

	}
	


	

	return 0;
}
