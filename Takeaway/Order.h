#pragma once
#include "ItemList.h"
class Order : public ItemList
{
public:
	Order();
	~Order();
	double calculateTotal();
	void printReceipt();
	void add(Item*);
	void remove(Item*);
	std::string toString();
private:
	double total;
};
