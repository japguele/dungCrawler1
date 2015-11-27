#include "stdafx.h"
#include "Weapon.h"


Weapon::Weapon(string val, string name, string desc)
{
	this->value = val;
	this->name = name;
	this->description = desc;
}

void Weapon::UseItem(Hero* hero){
	cout << "I have a " << value << " " << name << ". But " << description << endl;
}

std::string Weapon::Save(){
	return ",Weapon," + value + "," + name + "," + description;
}
Weapon::~Weapon()
{
}
