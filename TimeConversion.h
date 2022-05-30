#include <stdio.h>
#include <time.h>
#ifndef TimeConversion_H
#define TimeConversion_H
typedef float jam;
typedef float menit;
typedef float detik;
//jam ke menit
menit jamToMenit(jam toConvert);
//menit ke detik
detik menitToDetik(menit toConvert);
//detik ke menit
menit detikToMenit(detik toConvert);
jam menitToJam(menit toConvert);
void konversiJam(jam toConvert);
void konversiMenit(menit toConvert);
void konversiDetik(detik toConvert);
#endif
