#pragma once
#include "Chamber.h"
#include "ChamberFactory.h"
#include "Hero.h"

class Dungeon
{
public:
	Dungeon(int);
	~Dungeon();
private:
	ChamberFactory cf;
	Chamber* startChamber;
};

