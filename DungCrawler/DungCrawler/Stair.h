#pragma once

#include "Chamber.h"
class Stair :
	public Chamber
{
public:

	~Stair();
	Stair(Level* lvl, int x, int y);
	virtual void SetChamberInDirection(Chamber*, Direction);
private:
	Chamber* up;
	Chamber* down;
};

