#pragma once
#include <string>
#include "Potion.h"
#include "Weapon.h"
using namespace std;
class ItemFactory
{

private:
	int potionSize[3];
	string potionName[4];
	string potionDescription[3];

	string uselessSize[3];
	string uselessName[4];
	string uselessDescription[3];
public:
	ItemFactory();
	Item* CreateItem();
	Item* CreatePotion();
	Item* CreateUselessItem();
	~ItemFactory();
};

