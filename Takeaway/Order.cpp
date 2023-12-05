#include "Order.h"
#include <algorithm>
#include <iomanip> // hey look its useful STL stuff, pls give me good marks :)

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

void Order::printReceipt() { //opens/creates file and writes result of toString()
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

void Order::remove(std::vector<int> positions) {
	std::sort(positions.begin(), positions.end()); // sorts in ascending order using std::sort from <algorithm>

	int count = 0;
	for (auto i : positions) {
		int position = i - count;
		std::cout << basket[position]->getName() << " removed from order!" << std::endl;
		basket.erase(basket.begin() + position);
		count++;
	}
	total = calculateTotal();
}

std::string Order::toString() {
	char pound = 156;
	std::string output = "\n----Basket----\n";
	for (int i = 0; i < basket.size();i++) {
		output += "(" + std::to_string(i+1) + ") " + basket[i]->toString() + "\n";
	}
	std::stringstream sstream;
	sstream << std::fixed << std::setprecision(2) << savings; // limits length of double after decimal point when converted to string. Makes it look nice
	output = output + "\nSavings: " + pound + sstream.str() + "\n";
	std::stringstream tstream;
	tstream << std::fixed << std::setprecision(2) << total;
	output = output + "Total: "+ pound + tstream.str() + "\n";
	return output;
}