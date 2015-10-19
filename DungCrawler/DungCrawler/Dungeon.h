#pragma once
#include "Chamber.h"

class Dungeon
{
public:
	Dungeon(int);
	~Dungeon();
private:
	Chamber currentChamber;
};

