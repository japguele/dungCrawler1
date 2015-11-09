#include "stdafx.h"
#include "Dungeon.h"


Dungeon::Dungeon(int chambers) : cf(ChamberFactory())
{
	hero = new Hero("Jark");
	startChamber = cf.CreateChambers(chambers);
	int x = 0;
	int y = 0;
}

Hero* Dungeon::GetHero(){
	return hero;
}


Dungeon::~Dungeon()
{
}
