#pragma once
#include "Item.h"
#include <iostream>
class Potion :
	public Item
{
private:
	int value;
public:
	Potion(int, std::string, std::string);
	void UseItem(Hero*);
	~Potion();
	virtual std::string Save();
};

