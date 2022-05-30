#include <stdio.h>
#include <string.h>
#ifndef MassConversion_H
#define MassConversion_H
typedef float Kilo;
typedef float Ons;
typedef float Gram;
Ons KiloToOns(Kilo toConvert);
Gram OnsToGram(Ons toConvert);
Ons GramToOns(Gram toConvert);
Kilo OnsToKilo(Ons toConvert);
void fromKilo(Kilo mass);
void fromOns(Ons mass);
void fromGram(Gram mass);
#endif
