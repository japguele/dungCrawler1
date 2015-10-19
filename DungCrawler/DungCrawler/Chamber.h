#pragma once
#include "Level.h"
#include "Direction.h"


class Chamber
{
public:
	Chamber();
	Chamber(Chamber*, Direction);
	virtual ~Chamber();
	void SetChamberInDirection(Chamber*,Direction);
	

	Level* GetLevel();
	Chamber* GetChamberInDirection(Direction);

private:
	Level* level;
	Chamber* north;
	Chamber* east;
	Chamber* west;
	Chamber* south;
};

