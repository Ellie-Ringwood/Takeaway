#pragma once
#include "Item.h"
class Beverage :public Item
{
public:
	bool isAlcoholic();
private:
	double abv;
	int volume;
};

