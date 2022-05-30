#include "TimeConversion.h"
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
