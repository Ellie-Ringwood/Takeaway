#pragma once
#include <string>
class Item
{
public:
	Item(std::string, int, double);
	std::string toString();
private:
	std::string name;
	int calories;
	double price;
};