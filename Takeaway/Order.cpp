#include "Order.h"

Order::Order() {

}
Order::~Order() {

}

int Order::basketSize() {
	return basket.size();
}


double Order::calculateTotal() {
	double currentTotal = 0.0;
	for (int i = 0; i < basket.size();i++) {
		if (basket[i]->getType() == "a") {
			//SHAREABLE CODE GOES HERE!!!!!!!!!!!!!!!
		}
		currentTotal += basket[i]->getPrice();
	}
	return currentTotal;
}

void Order::printReceipt() {
	std::ofstream file;
	file.open("receipt.txt");
	if(file.is_open()) {
		file << toString();
	}
	else std::cout << "Unable to open file";
	file.close();
}

void Order::add(Item* item) {
	std::cout << item -> getName() << " added to order! \n" << std::endl;
	basket.push_back(item);
	total = calculateTotal();
	std::cout << toString();
}

void Order::remove(int position) {
	std::cout << basket[position]->getName() << " removed from order! \n" << std::endl;
	basket.erase(basket.begin() + position);
	total = calculateTotal();
	std::cout << toString();
}

std::string Order::toString() {
	char pound = 156;
	std::string output = "----Basket----\n";
	for (int i = 0; i < basket.size();i++) {
		output += "(" + std::to_string(i+1) + ") " + basket[i]->toString() + "\n";
	}
	output = output + "Savings: " + pound + std::to_string(savings) + "\n";
	output = output + "Total: "+ pound + std::to_string(total) + "\n";
	return output;
}