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
std::string Chamber::Save(int x,int y,int z){
//	int z = level->GetDepth();
	bool n = (north);
	bool e = (east);
	bool s = (south);
	bool w = (west);

	std::string a = "|Chamber," + std::to_string(xpos) + "," + std::to_string(ypos) + "," + std::to_string(z) + "," + std::to_string(n) + "," + std::to_string(e) + "," + std::to_string(s) + "," + std::to_string(w) + "," + description;
	if (enemy){
		a = a + enemy->Save();
	}

	for (std::string::iterator it = a.begin(); it != a.end(); ++it) {
		if (*it == ' ') {
			*it = '_';
		}
	}


	return a;


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

bool Chamber::AttackEnemy(int damage){
	//attack enemy
	if (enemy->TakeDamage(damage)){
		enemy = nullptr;
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
