#pragma once
#include <vector>
#include <string>
#include "Item.h"
class ItemList
{
public:
	//virtual std::string toString();
protected:
	std::vector<Item*> items;
};

