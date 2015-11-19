#pragma once
#include "Chamber.h"
#include "Enemy.h"
class BossChamber :
	public Chamber
{
public:
	BossChamber(Level* lvl, int x, int y, Enemy* en);
	~BossChamber();

	std::string Save(int x, int y, int z);
};

