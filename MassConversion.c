#include "MassConversion.h"
Ons KiloToOns(Kilo toConvert){
	return toConvert*10;
}
Gram OnsToGram(Ons toConvert){
	return toConvert*10;
}
Ons GramToOns(Gram toConvert){
	return toConvert/10;
}
Kilo OnsToKilo(Ons toConvert){
	return toConvert/10;
}
void fromKilo(Kilo mass){
	printf("%.2f kilo sama dengan %.2f ons\n",mass,KiloToOns(mass));
	printf("%.2f kilo sama dengan %.2f gram\n",mass,OnsToGram(KiloToOns(mass)));
}
void fromOns(Ons mass){
	printf("%.2f ons sama dengan %.2f kilo\n",mass,OnsToKilo(mass));
	printf("%.2f ons sama dengan %.2f gram\n",mass,OnsToGram(mass));
}
void fromGram(Gram mass){
	printf("%.2f gram sama dengan %.2f ons\n",mass,GramToOns(mass));
	printf("%.2f gram sama dengan %.2f kilo\n",mass,OnsToKilo(GramToOns(mass)));
}
