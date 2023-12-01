#include "Item.h"

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
	return name + ": " + pound + std::to_string(price) +  ", " + std::to_string(calories) + " cal ";
}

