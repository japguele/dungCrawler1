#include "stdafx.h"
#include "Chamber.h"


Chamber::Chamber(Level* lvl,int x,int y,std::string dis,Enemy* en)
{
	enemy = en;
	xpos = x;
	ypos = y;
	level = lvl;
	description = dis;
	north = nullptr;
	south = nullptr;
	west = nullptr;
	east = nullptr;
	if (rand() % 3 > 2){
		
	}
}
Enemy* Chamber::GetEnemy(){
	return enemy;
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

void Chamber::SetChamberInDirection(Chamber* cham, Direction dir){


	if (cham){
	switch (dir)
	{
	case Direction::North:
		north = cham;
		cham->south = this;
		break;
	case Direction::South:
		south = cham;
		cham->north = this;
		break;
	case Direction::West:
		west = cham;
		cham->east = this;
		break;
	case Direction::East:
		east = cham;
		cham->west = this;
		break;
	default:
		break;
	}
}
}
Level* Chamber::GetLevel(){
	return level;
}
int Chamber::GetXpos(){
	return xpos;
}
int Chamber::GetYpos(){
	return ypos;
}

void Chamber::AttackEnemy(int damage){
	//attack enemy
}


Chamber::~Chamber()
{
	delete north;
	delete south;
	delete east;
	delete west;
}
