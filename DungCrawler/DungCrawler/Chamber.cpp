#include "stdafx.h"
#include "Chamber.h"


Chamber::Chamber(Level* lvl,int x,int y,std::string dis,Enemy* en, Trap* t)
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
	trap = nullptr;
	if (t){
		trap = t;
	}
}
Enemy* Chamber::GetEnemy(){
	return enemy;
}

void Chamber::SetVisited(){
	visited = true;
}

bool Chamber::GetVisited(){
	return visited;
}
Trap* Chamber::GetTrap(){
	return trap;
}
string Chamber::GetMapIcon(){
	if (visited && enemy != nullptr){
		return "M";
	}
	else if (visited && trap != nullptr){
		return "T";
	}
	else if (visited){
		return "0";
	}
	else {
		return " ";
	}
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
		return nullptr;
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
		exits[0] = true;
		//cham->south->exits[2] = true;
		break;
	case Direction::South:
		south = cham;
		cham->north = this;
		exits[2] = true;
		//cham->north->exits[0] = true;
		break;
	case Direction::West:
		west = cham;
		cham->east = this;
		exits[3] = true;
		//cham->east->exits[1] = true;
		break;
	case Direction::East:
		east = cham;
		cham->west = this;
		exits[1] = true;
		//cham->west->exits[3] = true;
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

void Chamber::DefeatEnemy(){
	enemy = nullptr;
}

bool Chamber::AttackEnemy(int damage){
	//attack enemy
	if (enemy->TakeDamage(damage)){
		return true;
	}
	else {
		return false;
	}
}

array<bool,4> Chamber::GetExits(){
	return exits;
}


Chamber::~Chamber()
{
	delete north;
	delete south;
	delete east;
	delete west;
}
