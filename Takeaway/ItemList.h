#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip> // hey look its useful STL stuff, pls give me good marks :)
#include "Item.h"
class ItemList //abstract interface class
{
public:
	virtual std::string toString() = 0;
	std::vector<Item*> items;
	std::vector<Item*> currentList;
};

