#pragma once
#include <string>
class Hero;
class Item
{
protected:
	std::string name;
	std::string description;
public:
	Item();
	string GetName();
	string GetDescription();
	virtual void UseItem(Hero*);
	virtual ~Item();
};

