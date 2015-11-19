#include "stdafx.h"
#include "BossChamber.h"




BossChamber::BossChamber(Level* lvl, int x, int y,Enemy* en) : Chamber(lvl, x, y,"boss chamber", en, nullptr)
{
}


BossChamber::~BossChamber()
{
}
