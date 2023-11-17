#pragma once
#include "Item.h"
class Appetiser : public Item
{
public:
	void setShareable(bool);
	void setTwoForOne(bool);
private:
	bool shareable;
	bool twoForOne;
};
