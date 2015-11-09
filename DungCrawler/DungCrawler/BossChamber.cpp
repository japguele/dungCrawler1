#include "stdafx.h"

#include "BossChamber.h"
#include "Chamber.h"

class Chamber;


BossChamber::BossChamber(Level* lvl, int x, int y,Enemy* en) : Chamber(lvl, x, y,"boss chamber", en)
{
}


BossChamber::~BossChamber()
{
}
