#pragma once
#include "Item.h"
class Beverage :public Item
{
public:
	Beverage(std::string, int, double, double, int);
	~Beverage();
	bool isAlcoholic();
	std::string toString();
private:
	double abv;
	int volume;
};

