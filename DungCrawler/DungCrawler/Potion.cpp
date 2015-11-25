#include "stdafx.h"
#include "Potion.h"
#include "hero.h"

Potion::Potion(int val,std::string nam, std::string desc)
{
	this->value = val;
	this->name = nam;
	this->description = desc;
}

void Potion::UseItem(Hero* hero){
	cout << "I used the following item: " << name << endl;
	cout << description;
	hero->DrinkPotion(value);
}

Potion::~Potion()
{
}
