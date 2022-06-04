#include "TimeConversion.h"
void timeConvMain(){
	int choice;
	startingPoint:
	printf("\n\n\n\n");
	printf("\t\t[1] konversi dari jam\n");
	printf("\t\t[2] konversi dari menit\n");
	printf("\t\t[3] konversi dari detik\n");
	printf("\t\tMasukkan pilihan anda : ");
	scanf("%d",&choice);
	switch(choice){
		case 1 : 
		system("cls");
		konversiJam(getTimeValueToConv());break;
		case 2 : 
		system("cls");
		konversiMenit(getTimeValueToConv());break;
		case 3 : 
		system("cls");
		konversiDetik(getTimeValueToConv());break;
		default : printf("pilihan tersebut tidak ada\n");goto startingPoint;break;
	}
	printf("\n\t\t[]Tekan tombol apapun untuk kembali[]");
	getch();
}
int getTimeValueToConv(){
	int value;
	printf("masukkan angka yang akan dikonversi : ");
	scanf("%d",&value);
	return value;
}
//jam ke menit
menit jamToMenit(jam toConvert){
	return toConvert*60;
}
//menit ke detik
detik menitToDetik(menit toConvert){
	return toConvert*60;
}
//detik ke menit
menit detikToMenit(detik toConvert){
	return toConvert/60;
}
//menit ke jam
jam menitToJam(menit toConvert){
	return toConvert/60;
}
void konversiJam(jam toConvert){
	printf("%.2f jam sama dengan %.2f menit\n",toConvert,jamToMenit(toConvert));
	printf("%.2f jam sama dengan %.2f detik\n",toConvert,menitToDetik(jamToMenit(toConvert)));
}
void konversiMenit(menit toConvert){
	printf("%.2f menit sama dengan %.2f jam\n",toConvert,menitToJam(toConvert));
	printf("%.2f menit sama dengan %.2f detik\n",toConvert,menitToDetik(toConvert));
}
void konversiDetik(detik toConvert){
	printf("%.2f detik sama dengan %.2f menit\n",toConvert,detikToMenit(toConvert));
	printf("%.2f detik sama dengan %.2f jam\n",toConvert,menitToJam(detikToMenit(toConvert)));
}
