#pragma once

class Chamber;
class BossChamber :
	public Chamber
{
public:
	BossChamber(Level* lvl, int x, int y, Enemy* en);
	~BossChamber();
};

