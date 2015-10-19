#include "stdafx.h"
#include "Chamber.h"


Chamber::Chamber()
{	
}
Chamber::Chamber(Chamber* cham,Direction dir)
{
	SetChamberInDirection(cham, dir);
	
}
Chamber* Chamber::GetChamberInDirection(Direction dir){
	switch (dir)
	{
	case Direction::North:
		return north;
		break;
	case Direction::South:
		return south;
		break;
	case Direction::West:
		return west;
		break;
	case Direction::East:
		return east;
		break;
	default:
		return north;
		break;
	}
	
}

void Chamber::SetChamberInDirection(Chamber* cham,Direction dir){
	switch (dir)
	{
	case Direction::North:
		north = cham;
		break;
	case Direction::South:
		south = cham;
		break;
	case Direction::West:
		west = cham;
		break;
	case Direction::East:
		east = cham;
		break;
	default:
		break;
	}
}




Chamber::~Chamber()
{
	delete north;
	delete south;
	delete east;
	delete west;
}
