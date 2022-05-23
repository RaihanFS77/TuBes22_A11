#include <stdio.h>
#include <stdlib.h>

#include "Calculator.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	printf("Testing");
	Calculator test;

	testZone:

	createCalculator(&test);
	insertExpression(&test);
	if(!isValidExpression(test.input)){
		sleep(1);
		goto testZone;
	}
	checkFrontMinus(test.input);

	test.CalcTree = expressionToTree(test.input,0,strlen(test.input)-1);
	printf("Success?");
	getch();
	bool sukses = isCalculationSuccess(&test, test.CalcTree);
	printf("Sussccess?");
	bool isSuccess;
	test.result = startCalculation(test.CalcTree, &isSuccess);

	printf("%f",test.result);


	

	return 0;
}
