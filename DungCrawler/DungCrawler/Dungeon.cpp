#include "stdafx.h"
#include "Dungeon.h"


Dungeon::Dungeon(int chambers) : cf(new ChamberFactory())
{
	hero = new Hero("Jark");
	startChamber = cf->CreateChambers(chambers);
	int x = 0;
	int y = 0;
	hero->SetCurrentChamber(startChamber);
}

Hero* Dungeon::GetHero(){
	return hero;
}

ChamberFactory* Dungeon::GetChamberFactory(){
	return cf;
}




Dungeon::~Dungeon()
{
}
