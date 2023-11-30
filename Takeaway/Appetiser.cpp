#include "Appetiser.h"

Appetiser::Appetiser(std::string iname, int icalories, double iprice, bool ishareable, bool itwoForOne):Item(iname, icalories, iprice) {
	//std::cout << "appetiser created" << std::endl;
	shareable = ishareable;
	twoForOne = itwoForOne;
}

Appetiser::~Appetiser() {

}

void Appetiser::setShareable(bool inputShareable) {
	shareable = inputShareable;
}

void Appetiser::setTwoForOne(bool inputTwoForOne) {
	twoForOne = inputTwoForOne;
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