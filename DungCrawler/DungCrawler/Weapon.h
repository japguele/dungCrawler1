#pragma once
#include "Item.h"
#include <iostream>
class Weapon :
	public Item
{
private:
	string value;
public:
	Weapon(string, string, string);
	void UseItem(Hero* hero);
	~Weapon();
};

