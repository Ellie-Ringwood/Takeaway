#include "Appetiser.h"

Appetiser::Appetiser(std::string itype,std::string iname, int icalories, double iprice, bool ishareable, bool itwoForOne):Item(itype,iname, icalories, iprice) {
	//std::cout << "appetiser created" << std::endl;
	shareable = ishareable;
	twoForOne = itwoForOne;
}

Appetiser::~Appetiser() {

}

bool Appetiser::getShareable() {
	return shareable;
}

std::string Appetiser::toString() {
	if (shareable == true) {
		return Item::toString() + "(shareable)";
	}
	if (twoForOne == true){
		return Item::toString() + "(2-4-1)";
	}
	else {
		return Item::toString();
	}
}