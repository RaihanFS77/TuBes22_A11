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
	checkForFormatting(&test.input);
	if(!isValidExpression(test.input)){
		sleep(1);
		goto testZone;
	}
	test.CalcTree = expressionToTree(test.input,0,countStringLength(test.input)-1);
	printf("expression to tree success maybe?");

	bool sukses = isCalculationSuccess(&test, test.CalcTree);
	printf("iscalculationsuccess ?");
	bool isSuccess;
	test.result = startCalculation(test.CalcTree, &isSuccess);

	printf("\n\n-hasilnya : %f\n",test.result);


	

	return 0;
}
