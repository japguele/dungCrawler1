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
string Chamber::GetMapIconCheatmode(){
	if (trap != nullptr){
		return "T";
	}
	else if (enemy != nullptr){
		return "M";
	}
	else {
		return "O";
	}
}
string Chamber::GetMapIconHealthmode(){
	if (trap != nullptr){
		return "T";
	}
	else if (enemy != nullptr){
		return to_string(enemy->GetHealth());
	}
	else {
		return "O";
	}
}
string Chamber::GetMapIcon(){
	if (visited && trap != nullptr){
		return "T";
	}
	else if (visited && enemy != nullptr){
		return "M";
	} 
	else if (visited){
		return "O";
	}
	else {
		return " ";
	}
}
string Chamber::GetMapIconSpanMode(){
	if (spanningTree) {
		return "O";
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
int Chamber::GetWeight(){
	int x = 1;
	if (enemy != nullptr){
		x = x + 10;
	}
	if (trap != nullptr){
		x = x + 2;
	}
	return x;
}

bool Chamber::DirectionIsOpen(Direction direction){
	
	switch (direction) {
	case Direction::North:
		return !exits[0];
		break;
	case Direction::South:
		return !exits[1];
		break;
	case Direction::West:
		return !exits[2];
		break;
	case Direction::East:
		return !exits[3];
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
	if (trap){
		a = a + trap->Save();
	}

	for (std::string::iterator it = a.begin(); it != a.end(); ++it) {
		if (*it == ' ') {
			*it = '_';
		}
	}


	return a;


}

void Chamber::SetInAccessibleDirection(Direction direction) {
	switch (direction) {
		case Direction::North:
			exits[0] = true;
			this->north->exits[1] = true;
			break;
		case Direction::South:
			exits[1] = true;
			this->south->exits[0] = true;
			break;
		case Direction::West:
			exits[2] = true;
			this->west->exits[3] = true;
			break;
		case Direction::East:
			exits[3] = true;
			this->east->exits[2] = true;
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
			//exits[0] = true;
			//cham->south->exits[2] = true;
			break;
		case Direction::South:
			south = cham;
			cham->north = this;
			//exits[2] = true;
			//cham->north->exits[0] = true;
			break;
		case Direction::West:
			west = cham;
			cham->east = this;
			//exits[3] = true;
			//cham->east->exits[1] = true;
			break;
		case Direction::East:
			east = cham;
			cham->west = this;
			//exits[1] = true;
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
	if (enemy){
		if (enemy->TakeDamage(damage)){
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}

array<bool,4> Chamber::GetExits(){
	return exits;
}


Chamber::~Chamber()
{
	/*delete north;
	delete south;
	delete east;
	delete west;*/
}