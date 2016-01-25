#pragma once
#include "stdafx.h"
#include "Item.h"

#include "ChamberWeight.h"
#include "Hero.h"

#include <iostream>
#include <deque>
#include <unordered_set>

using namespace std;

class SilverCompass : public Item {
public:
	SilverCompass(string name, string description);
	~SilverCompass();

	void UseItem(Hero*);

private:
	Direction GetOppositeDirection(Direction direction);
};