#include "Item.h"
#include <iomanip>

Item::Item(std::string itype,std::string inputName, int inputCalories, double inputPrice) {
	//std::cout << "item created" << std::endl;
	type = itype;
	name = inputName;
	calories = inputCalories;
	price = inputPrice;
}

double Item::getPrice() {
	return price;
}

std::string Item::getName() {
	return name;
}

std::string Item::getType() {
	return type;
}

std::string Item::toString() {
	char pound = 156;
	std::stringstream stream;
	stream << std::fixed << std::setprecision(2) << price;
	return name + ": " + pound + stream.str() + ", " + std::to_string(calories) + " cal ";
}

bool Item::getTwoForOne() {
	return false;
}

