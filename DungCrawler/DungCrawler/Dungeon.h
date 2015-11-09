#pragma once

#include "ChamberFactory.h"
#include "Hero.h"

class Dungeon
{
public:
	Dungeon(int);
	~Dungeon();
	Hero* GetHero();
private:
	ChamberFactory cf;
	Chamber* startChamber;
	Hero* hero;
};

