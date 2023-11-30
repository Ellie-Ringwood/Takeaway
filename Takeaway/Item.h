#pragma once
#include <string>
#include <sstream>
#include <iostream>
class Item
{
public:
	Item(std::string, int, double);
	//Item();
	virtual std::string toString();
protected:
	std::string name;
	int calories;
	double price;
};