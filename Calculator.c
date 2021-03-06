#include "Calculator.h"

double startCalculation(addrNode Node, bool *isSuccess)
{

    // cek Node dari suatu node apakah operator, apabila operator maka
    if (Node->isSymbol)
    {
        // Tentukan operand dan hitung
        switch (Node->symbol)
        {
        // tambah
        case PLUS:
        {
            return startCalculation(Node->leftChild, isSuccess) + startCalculation(Node->rightChild, isSuccess);
            break;
        }
        // kurang
        case MINUS:
        {
            return startCalculation(Node->leftChild, isSuccess) - startCalculation(Node->rightChild, isSuccess);
            break;
        }
        // bagi
        case BAGI:
        {
            // cek apabila terjadi pembagian oleh 0
            if (startCalculation(Node->rightChild, isSuccess) == 0)
            {
                (*isSuccess) = false;
                return MAX;
            }
            else
                return startCalculation(Node->leftChild, isSuccess) / startCalculation(Node->rightChild, isSuccess);
            break;
        }
        case KALI:
        {
            // perkalian
            return startCalculation(Node->leftChild, isSuccess) * startCalculation(Node->rightChild, isSuccess);
            break;
        }
        case PANGKAT:
        {
            // pangkat
            return pow(startCalculation(Node->leftChild, isSuccess), startCalculation(Node->rightChild, isSuccess));
            break;
        }
        case PERSENTASE:
        {
            // persentase
            return (startCalculation(Node->leftChild, isSuccess) * startCalculation(Node->rightChild, isSuccess)) / 100;
            break;
        }
        case AKAR_KUADRAT:
        {
            // akar
            return pow(startCalculation(Node->rightChild, isSuccess), 1 / startCalculation(Node->leftChild, isSuccess));
            break;
        }
        }
    }

    // apabila Node bukanlah suatu operator

    return Node->number;
    /**
     * Original Source : https://www.programmersought.com/article/95294413292/ dan https://github.com/zharmedia386/CalculatorUsingBinaryTree
     * Melakukan perhitungan terhadap suatu sub-tree
     * Mengembalikan hasil perhitungan jika terdapat operator (Node berisi operator)
     * Mengembalikan nilai number jika tidak terdapat operator (Node berisi number)
     */
}

double checkString(char input[], int start, int end)
{
    int counter;
    int positiveFlag = 1;    // apakah positif atau negatif
    int decimalFlag = 0;     // apakah decimal
    double num = 0;          // angka yang ditemukan akan di return
    double divFactor = 10.0; // seberapa jauh dari titik desimal suatu nominal

    // apakah negatif
    if (input[start] == MINUS)
    {
        positiveFlag = -1;
        start++;
    }

    // melakukan travel parsing dari string ke number
    for (counter = start; counter <= end; counter++)
    {
        // bukan desimal dan bukan angka
        if (!isdigit(input[counter]) && input[counter] != PointDecimal)
        {
            return MAX;
        }

        // apakah desimal
        if (input[counter] == PointDecimal)
        {
            decimalFlag++;
            counter++;
        }

        // char ke number
        if (!decimalFlag)
        {
            num = num * 10 + input[counter] - '0';
        }
        else
        {
            num = num + (input[counter] - '0') / divFactor;
            divFactor *= 10;
        }
    }

    return num * positiveFlag;
    /**
     * Original Source : https://www.programmersought.com/article/95294413292/
     * Melakukan pengecekan terhadap suatu string
     * Mengembalikan hasil konversi number jika tidak ditemukan operator pada string
     * Mengembalikan nilai Infinity jika terdapat operator pada string
     */
}

int findOperator(char input[], int start, int end)
{
    int posPlusOrSub = 0; // Position of plus and minus signs
    int numPlusOrSub = 0; // Number of plus and minus signs
    int posDivOrMul = 0;  // Multiply and divide and percenting sign position
    int numDivOrMul = 0;  // Number of multiplication and division and percenting numbers
    int posPowOrRoot = 0; // Power and square root sign position
    int numPowOrRoot = 0; // Number of the result after powering or square rooting

    int in_brackets = 0; // Identifiers not in parentheses
    int counter;

    for (counter = start; counter <= end; counter++)
    {
        if (input[counter] == KURUNG_BUKA)
            in_brackets++;
        else if (input[counter] == KURUNG_TUTUP)
            in_brackets--;

        // Jika diluar tanda kurung
        if (!in_brackets)
        {
            if (input[counter] == PLUS || input[counter] == MINUS)
            {
                // check apakah sebelumnya adalah operator
                if (counter != start && isdigit(input[counter - 1]))
                {
                    posPlusOrSub = counter;
                    numPlusOrSub++;  
                }
                 // check apabila dibelakangnya adalah kurung buka/kurung tutup
                else if ((input[counter - 1] == KURUNG_BUKA || input[counter - 1] == KURUNG_TUTUP))
                {
                    posPlusOrSub = counter;
                    numPlusOrSub++;
                }
            }

            else if(input[counter] == KALI || input[counter] == BAGI || input[counter] == PERSENTASE){
                posDivOrMul = counter;
                numDivOrMul++; 
            }

            else if (input[counter] == PANGKAT || input[counter] == AKAR_KUADRAT)
            {
                posPowOrRoot = counter;
                numPowOrRoot++;
            }
        }
    }
	
    // posisi operator yang diprioritaskan
    int posOperator = -1;

    // Temukan posisi root node dimulai dengan urutan operator derajat terendah
    if (numPlusOrSub)
        posOperator = posPlusOrSub;
    else if (numDivOrMul)
        posOperator = posDivOrMul;
    else if (numPowOrRoot)
        posOperator = posPowOrRoot;
    return posOperator;

    /**
     * Menemukan operator dengan aturan derajat yang telah ditentukan
     * Mengembalikan posisi operator tersebut dalam string
     */
}

addrNode expressionToTree(char input[], int start, int end)
{
    /**
     * Original Source : https://www.programmersought.com/article/95294413292/
     * Membuat expression tree
     * Mengembalikan tree yang telah berisi expression
     */
    
    double num;
    addrNode Node = (addrNode)malloc(sizeof(struct TNode));
    if (start > end)
        return NULL;
            
    num = checkString(input, start, end);
    if (num != MAX)
    {
        Node->isSymbol = false;
        Node->number = num;
        Node->leftChild = NULL;
        Node->rightChild = NULL;
        return Node;
    }

    int posNode = findOperator(input, start, end);

    if (posNode == -1)
        return expressionToTree(input, start + 1, end - 1);

    Node->isSymbol = true;
    Node->symbol = input[posNode];
    Node->leftChild = expressionToTree(input, start, posNode - 1);
    Node->rightChild = expressionToTree(input, posNode + 1, end);

    return Node;
}

void deleteTree(addrNode Node)
{
    /**
     * Menghapus semua node pada tree
     * IS : node pada tree tersedia
     * FS : node pada tree telah di dealokasi
     */
    if (Node == NULL)
        return;
    deleteTree(Node->leftChild);
    deleteTree(Node->rightChild);
    free(Node);
}

void createCalculator(Calculator *calculator)
{
    /**
     * Membuat calculator baru
     * IS : calculator random value
     * FS : calculator default value
     */
    // alokasi dan assignment
    memset(calculator->input, '\0', sizeof(calculator->input));
    // mengkosongkan result dari suatu kalkulator
    calculator->result = 0;
    // malloc suatu tree baru yang akan digunakan kalkulator
    calculator->CalcTree = (addrNode)malloc(sizeof(Node));
}

bool isValidExpression(char expression[])
{

    /**
     * Mengecek apakah pada string ekspresi memuat karakter illegal (bukan operator/simbol matematis)
     * Mengembalikan true jika tidak ada karakter ilegal dan jumlah kurung buka tutup sama
     * Mengembalikan false jika terdapat karakter ilegal dan atau kurung buka tutup tidak sama
     */
    if(checkInputAsRule(expression) && isBracketEqual(expression))
    	return true;
	return false;
}

bool checkInputAsRule(char expression[]){
	/**
     * Mengecek apakah pada string ekspresi memuat karakter illegal (bukan operator/simbol matematis)
     * Mengembalikan true jika tidak ada karakter ilegal
     * Mengembalikan false jika terdapat karakter ilegal
     */
    int totalChar;

    // apakah ada simbol yang tidak merupakan operator matematis

    for (totalChar = (countStringLength(expression) - 1 ); totalChar >= 0; totalChar--)
    {
        if (!isdigit(expression[totalChar]) && !isOperator(expression[totalChar]) && !isBracket(expression[totalChar]))
        {
            printf("Ekspresi matematis tidak valid!\n");
            return false;
        }
    }
	return true;
}

bool isBracketEqual(char expression[]){
	int countOBracket=0,countCBracket=0;
	int count;
	for(count = 0;expression[count] != '\0';count++){
		if(expression[count] == '(')
			countOBracket++;
		else if(expression[count] == ')')
			countCBracket++;
	}
	if(countOBracket == countCBracket)
		return true;
	printf("jumlah kurung buka dan kurung tutup tidak seimbang\n");
	return false;
}

bool isOperator(char expression){
	if(	expression ==PointDecimal || 
		expression ==PLUS ||
		expression ==MINUS ||
		expression ==KALI ||
		expression ==BAGI ||
		expression ==AKAR_KUADRAT ||
		expression ==PANGKAT ||
		expression ==PERSENTASE)
		return true;
	return false;
}

bool isBracket(char expression){
	if(expression == KURUNG_BUKA || expression == KURUNG_TUTUP)
		return true;
	return false;
}
void checkForFormatting(char *expression){
	checkWhiteSpace(expression);
	checkFrontBracketAsKali(expression);
	checkFrontMinus(expression);
}
void checkWhiteSpace(char *expression){
	int count,countFromWS;
	for(count = 0 ;expression[count] !='\0'; count++){
		if(expression[count] == ' ' ){
			for(countFromWS=count;expression[countFromWS+1] != '\0';countFromWS++){
				expression[countFromWS] = expression[countFromWS+1];
				expression[countFromWS+1] = '\0';
			}
		}
	}
}
void checkFrontMinus(char *expression)
    {
        /**
         * Mengecek apakah simbol pertama merupakan minus
         * IS : ekspresi string
         * FS1 : ekspresi string digeser ke kanan 1, dan pada index 0 insert '0'
         * FS2 : ekspresi string tidak dimanipulasi
         */
        int forLoop;
        if (expression[0] == '-')
        {
            for (forLoop = countStringLength(expression); forLoop >= 0; forLoop--)
            {
                expression[forLoop + 1] = expression[forLoop];
            }
            expression[0] = '0';
        }
    }
void checkFrontBracketAsKali(char *expression){
	int count,countFromBracket,countTemp,countLength;
	char temp[countStringLength(expression)+20];
	for(count = 0;expression[count] !='\0'; count++){
		countTemp = 0;
		countFromBracket = 0;
		if((isdigit(expression[count-1])||expression[count-1]==')') && expression[count] == '(' ){
			countLength= 0;
			for(countFromBracket=count;expression[countFromBracket] != '\0';countFromBracket++){
				temp[countTemp] = expression[countFromBracket];
				countTemp++;
				countLength++;
			}
			countFromBracket=count;
			for(countTemp = 0;countTemp<countLength;countTemp++){
				expression[countFromBracket+1] = temp[countTemp];
				temp[countTemp] = '\0';
				countFromBracket++;
			}
			expression[count] = '*';
		}
	}
}

void insertExpression(Calculator * calculator)
    {
        // meminta input dari pengguna
        char* temp[500];
        printf("\n\n");
        // gridLayout();
        printf("\t\t[] Enter your mathematical expression: ");
        fflush(stdin);
        gets(temp);
        if(strlen(temp)>=200){
            calculator->input[0] = "a";
        }else{
            strcpy(calculator->input,temp);
        }
        printf("%s",calculator->input);
        printf("\n\n");

        /**
         * Memasukan string ekspresi kedalam kalkulator
         * IS : kalkulator dengan ekspresi kosong
         * FS : kalkulator dengan ekspresi terisi oleh inputan user
         */
    }

bool isCalculationSuccess(Calculator * calculator, addrNode Node)
    {
        /**
         * Melakukan kalkulasi ekspresi matematika pada tree
         * Mengembalikan true jika proses kalkulasi berhasil
         * Mengembalikan false jika proses kalkulasi gagal
         */
        bool isSuccess = true;

        calculator->result = startCalculation(Node, &isSuccess);

        return isSuccess;
    }

void printResult(Calculator calculator, bool isSuccess){
	system("cls");
	
	// print calculator sesuai dengan format
    if(!isSuccess){
    	// Gagal
        printf("\n\n");
        printf("  = %s","Error : Tidak dapat membagi dengan 0");
        sleep(2);
    }
    else if (ceil(calculator.result) > calculator.result){
    	// Berhasil dan menghasilkan desimal
        printf("\n\n");
         printf("\t-- RESULT OF THE CALCULATION -- \n\n");
        printf("\t|\t%s",calculator.input);
        printf(" = %.3f\t|\n",calculator.result);
    }
	else{
		// Berhasil dan menghasilkan bilangan bulat
        printf("\n\n");
        printf("\t-- RESULT OF THE CALCULATION -- \n\n");
        printf("\t|\t%s",calculator.input);
        printf(" = %d\t|\n",(int)calculator.result);
    }
}
   
bool stayCalculating()
    {
        /**
         * mengecek apakah pengguna mengulang proses kalkulasi
         * Mengembalikan true jika iya
         * Mengembalikan false jika tidak
         */
        char input;
        while (true)
        {
            printf("\n\t[] Tetap menggunakan kalkulator (y/n) [] :");
            fflush(stdin);
            scanf("%c", &input);
            input = toupper(input);
            if (input == 'Y')
                return true;
            else if (input == 'N')
                return false;
            else
            {
                printf("Invalid input please try again \n");
                sleep(1);
            }
        }
    }

