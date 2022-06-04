#include <stdio.h>
#include <time.h>
#ifndef TimeConversion_H
#define TimeConversion_H
typedef float jam;
typedef float menit;
typedef float detik;
//main program for time conversion
void timeConvMain();
// get value to convert
int getTimeValueToConv();
//konversi jam ke menit
menit jamToMenit(jam toConvert);
//konversi menit ke detik
detik menitToDetik(menit toConvert);
//konversi detik ke menit
menit detikToMenit(detik toConvert);
//konversi menit ke jam
jam menitToJam(menit toConvert);
void konversiJam(jam toConvert);
//konversi dari jam
void konversiMenit(menit toConvert);
//konversi dari menit
void konversiDetik(detik toConvert);
//konversi dari detik
#endif
