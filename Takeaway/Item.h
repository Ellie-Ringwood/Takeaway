#pragma once
#include <string>
class Item
{
public:
	std::string toString();
private:
	std::string name;
	int calories;
	double price;
};