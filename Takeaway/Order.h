#pragma once
#include "ItemList.h"
#include <fstream>
class Order : public ItemList
{
public:
	Order();
	~Order();
	double calculateTotal();
	void printReceipt();
	void add(Item*);
	void remove(std::vector<int>);
	std::string toString();
	int basketSize();
private:
	double total;
	double savings;
	std::vector<Item*> basket;
};
