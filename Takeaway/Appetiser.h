#pragma once
#include "Item.h"
class Appetiser : public Item
{
public:
	Appetiser(std::string, int, double, bool, bool);
	~Appetiser();
	void setShareable(bool);
	void setTwoForOne(bool);
	std::string toString();
private:
	bool shareable;
	bool twoForOne;
};
