#include "Item.h"

Item::Item(std::string inputName, int inputCalories, double inputPrice) {
	//std::cout << "item created" << std::endl;
	name = inputName;
	calories = inputCalories;
	price = inputPrice;
}

std::string Item::toString() {
	char pound = 156;
	return name + ": " + pound + std::to_string(price) +  ", " + std::to_string(calories) + " cal ";
}

