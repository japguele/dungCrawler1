#pragma once
#include <string>
class Item
{
public:
	string name;
	Item();
	virtual ~Item();
	virtual std::string Save();
};

