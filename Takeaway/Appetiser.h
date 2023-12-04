#pragma once
#include "Item.h"
class Appetiser : public Item
{
public:
	Appetiser(std::string, std::string, int, double, bool, bool);
	~Appetiser();
	std::string toString();
	bool getTwoForOne();
private:
	bool shareable;
	bool twoForOne;
};
