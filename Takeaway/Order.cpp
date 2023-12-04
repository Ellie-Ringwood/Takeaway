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
	int twoForOneCount = 0;
	std::vector<double> prices241;

	for (int i = 0; i < basket.size();i++) {
		if (basket[i]->getType() == "a") {
			if (basket[i]->getTwoForOne() == 1) { //gets all items with 241 deals
				twoForOneCount += 1;
				prices241.push_back(basket[i]->getPrice());
			}
		}
		currentTotal += basket[i]->getPrice();
	} 

	if (twoForOneCount > 1) { 
		savings = 0;
		for (int i = 0; i < twoForOneCount / 2;i++) {
			double smallestPrice = 1000;
			double smallestPos = -1;
			for (int e= 0; e < prices241.size();e++) {
				if (prices241[e] < smallestPrice) {
					smallestPrice = prices241[e];
					smallestPos = e;
				}
				
			}
			savings += smallestPrice;
			prices241.erase(prices241.begin() + smallestPos);
		}
	}
	currentTotal -= savings;
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
	std::cout << item -> getName() << " added to order!" << std::endl;
	basket.push_back(item);
	total = calculateTotal();
}

void Order::remove(vector<int> positions) {
	for (int i = 0; i < positions.size();i++) {
		std::cout << positions[i] << std::endl;
		std::cout << basket[positions[i]]->getName() << " removed from order! \n" << std::endl;
		basket.erase(basket.begin() + positions[i]);
	}
	total = calculateTotal();
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