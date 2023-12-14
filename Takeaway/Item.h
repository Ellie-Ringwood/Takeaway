#pragma once
#include <string>
#include <format>
#include <sstream>
#include <iostream>
class Item
{
public:
	Item(std::string, std::string, int, double);
	Item();
	virtual std::string toString();
	double getPrice() const;
	std::string getName() const;
	std::string getType() const;
	virtual bool getTwoForOne();
protected:
	std::string type;
	std::string name;
	int calories;
	double price;
};