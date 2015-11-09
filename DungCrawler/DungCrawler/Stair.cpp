#include "stdafx.h"
#include "Chamber.h"


#include "Stair.h"



Stair::Stair(Level* lvl,int x,int y,Enemy* en) : Chamber(lvl,x,y,"stair",en)
{
	
}


Stair::~Stair()
{
}
void Stair::SetChamberInDirection(Chamber* chamber,Direction d){
	switch (d)
	{
	case Direction::North:
		north = chamber;
		break;
	case Direction::South:
		south = chamber;
		break;
	case Direction::West:
		west = chamber;
		break;
	case Direction::East:
		east = chamber;
		break;
	case Direction::Up:
		up = chamber;
		break;
	case Direction::Down:
		down = chamber;
		break;
	default:
		break;
	}
}
