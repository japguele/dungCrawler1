#pragma once
#include "stdafx.h"

#include "Item.h"
#include "Hero.h"

#include <iostream>
#include <list>
#include <deque>
#include <unordered_set>
#include <unordered_map>

class Talisman : public Item {

public:
	Talisman(std::string name, std::string description);
	~Talisman();

	void UseItem(Hero*); //override sort of
};