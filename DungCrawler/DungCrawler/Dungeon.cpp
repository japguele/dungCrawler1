#include "stdafx.h"
#include "Dungeon.h"


Dungeon::Dungeon(int chambers) : cf(ChamberFactory())
{
	startChamber = cf.CreateChambers(chambers);
	int x = 0;
	int y = 0;
}


Dungeon::~Dungeon()
{
}
