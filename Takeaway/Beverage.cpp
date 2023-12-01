#include "Beverage.h"

Beverage::Beverage(std::string itype, std::string iname, int icalories, double iprice, double iabv, int ivolume) : Item(itype, iname, icalories, iprice) {
	//std::cout << "beverage created" << std::endl;
	abv = iabv;
	volume = ivolume;
}

std::string Beverage::toString() {
	return Item::toString() + "(" + std::to_string(volume) + "ml, " +std::to_string(abv) + "% abv)";
}