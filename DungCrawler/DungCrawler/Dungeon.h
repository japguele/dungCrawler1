#pragma once

#include "ChamberFactory.h"
#include "Hero.h"

class Dungeon
{
public:
	Dungeon(int);
	~Dungeon();
	Hero* GetHero();
	ChamberFactory* GetChamberFactory();
private:
	ChamberFactory* cf;
	Chamber* startChamber;
	Hero* hero;
};

