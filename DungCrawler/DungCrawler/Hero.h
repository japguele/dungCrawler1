#pragma once
#include "Unit.h"
#include "Chamber.h"

class Hero :
	public Unit
{
public:
	Hero();
	~Hero();
private:

	Chamber* currentChamber();

};

