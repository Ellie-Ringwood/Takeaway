#pragma once
#include "ItemList.h"
class Order : public ItemList
{
public:
	double calculateTotal();
	void printReceipt();
	void add(Item*);
	void remove(Item*);
private:
	double total;
};
