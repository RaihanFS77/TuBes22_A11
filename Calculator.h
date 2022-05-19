#include "CalcTree.h"
#ifndef Calculator_H
#define Calculator_H


typedef struct Calculator{
	char input[200];
	double result;
	addrNode CalcTree;	
}Calculator;

double startCalculation(addrNode root, bool *isSuccess);
/**
 * [Modified] From https://www.programmersought.com/article/95294413292/
 * Melakukan perhitungan terhadap suatu sub-tree
 * Mengembalikan hasil perhitungan jika terdapat operator (root berisi operator)
 * Mengembalikan nilai number jika tidak terdapat operator (root berisi number)
 */

double checkString(char str[],int start,int end);
/**
 * [Modified] From https://www.programmersought.com/article/95294413292/
 * Melakukan pengecekan terhadap suatu string
 * Mengembalikan hasil konversi number jika tidak ditemukan operator pada string
 * Mengembalikan nilai MAX jika terdapat operator pada string
 */

int findOperator(char str[],int start,int end);
/**
 * Menemukan operator dengan aturan derajat yang telah ditentukan
 *  1. PLUS or MINUS
 *  2. MULTIPLY or DIVISION
 *  3. SQUARE_ROOT or PERCENTAGE or POWER
 * Mengembalikan posisi operator tersebut dalam string
 */

addrNode expressionToTree(char str[],int start,int end);
/**
 * [Modified] From https://www.programmersought.com/article/95294413292/
 * Membuat expression tree
 * Mengembalikan tree yang telah berisi expression
 */

void deleteTree(addrNode root);
/**
 * Menghapus semua node pada tree
 * IS : node pada tree tersedia
 * FS : node pada tree telah di dealokasi
 */
 
 
 void createCalculator(Calculator *calculator);
/**
 * Membuat calculator baru
 * IS : calculator random value
 * FS : calculator default value
 */

bool isValidExpression(char *expression);
/**
 * Mengecek apakah pada string ekspresi memuat karakter illegal (bukan operator/simbol matematis)
 * Mengembalikan true jika tidak ada karakter ilegal
 * Mengembalikan false jika terdapat karakter ilegal
 */
 
void checkFrontMinus(char *expression);
/**
 * Mengecek apakah simbol pertama merupakan minus
 * IS : ekspresi string
 * FS1 : ekspresi string digeser ke kanan 1, dan pada index 0 insert '0'
 * FS2 : ekspresi string tidak dimanipulasi
 */
 
void insertExpression(Calculator *calculator);
/**
 * Memasukan string ekspresi kedalam kalkulator
 * IS : kalkulator dengan ekspresi kosong
 * FS : kalkulator dengan ekspresi terisi oleh inputan user
 */

bool isCalculationSuccess(Calculator *calculator, addrNode root); 
/**
 * Melakukan kalkulasi ekspresi matematika pada tree
 * Mengembalikan true jika proses kalkulasi berhasil
 * Mengembalikan false jika proses kalkulasi gagal
 */

void printResult(Calculator calculator, bool isSuccess);
/**
 * Menampilkan hasil expresi
 * IS : layar kosong
 * FS : tampil hasil perhitungan ekspresi aritmatik dan ekspresinya
 */

bool stayCalculating();
/**
 * mengecek apakah pengguna mengulang proses kalkulasi
 * Mengembalikan true jika iya
 * Mengembalikan false jika tidak
 */
 
#endif
