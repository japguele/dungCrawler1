#pragma once
#include <string>
class Hero;
class Item
{
protected:
	Hero* hero;
	std::string name;
	std::string decription;
public:
	Item();
	string GetName();
	string GetDescription();
	virtual void UseItem(Hero*);
	virtual ~Item();
};

