#pragma once
#include <vector>
#include <string>
#include "Item.h"
class ItemList //abstract interface class
{
public:
	virtual std::string toString() = 0;
protected:
	std::vector<Item*> items;
};

