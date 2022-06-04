#include <stdio.h>
#include <string.h>
#ifndef MassConversion_H
#define MassConversion_H
typedef float Kilo;
typedef float Ons;
typedef float Gram;
//main module in mass conversion
void massConvMain();
//meminta input dari user untuk dikonversi
float getMassValueToConv();
//konversi dari kilogram ke ons
Ons KiloToOns(Kilo toConvert);
//konversi dari ons ke gram
Gram OnsToGram(Ons toConvert);
//konversi dari gram ke ons
Ons GramToOns(Gram toConver);
//konversi dari ons ke kilogram
Kilo OnsToKilo(Ons toConvert);
//konversi dari kilogram
void fromKilo(Kilo mass);
////konversi dari ons
void fromOns(Ons mass);
//konversi dari gram
void fromGram(Gram mass);
#endif
