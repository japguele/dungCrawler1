#pragma once
#include "Chamber.h"
#include <string>

class BossChamber :
	public Chamber
{
public:
	BossChamber(Level* lvl, int x, int y);
	~BossChamber();
};

