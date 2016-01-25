#pragma once
#include "stdafx.h"
#include "Item.h"

#include "ChamberWeight.h"

using namespace std;

class SilverCompass : public Item {
public:
	SilverCompass(string name, string description);
	~SilverCompass();

	void UseItem(Hero*);
};