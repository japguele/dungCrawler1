#include "stdafx.h"
#include "Chamber.h"


#include "Stair.h"



Stair::Stair(Level* lvl,int x,int y,Enemy* en) : Chamber(lvl,x,y,"stair",en, nullptr)
{
	
}


Stair::~Stair()
{
}
string Stair::GetMapIconCheatmode(){
	return "S";
}

string Stair::GetMapIcon(){
	if (visited){
		return "S";
	}
	else {
		return " ";
	}
}

Chamber* Stair::GetChamberInDirection(Direction dir){
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
	case Direction::Up:
		return up;
		break;
	case Direction::Down:
		return down;
		break;
	default:
		break;
	}

}
void Stair::SetChamberInDirection(Chamber* cham,Direction dir){
	switch (dir)
	{
	case Direction::North:
		north = cham;
		cham->south = this;
		exits[0] = true;
		break;
	case Direction::South:
		south = cham;
		cham->north = this;
		exits[2] = true;
		break;
	case Direction::West:
		west = cham;
		cham->east = this;
		exits[3] = true;
		break;
	case Direction::East:
		east = cham;
		cham->west = this;
		exits[1] = true;
		break;
	case Direction::Up:
		up = cham;
		break;
	case Direction::Down:
		down = cham;
		break;
	default:
		break;
	}
}

std::string Stair::Save(int x, int y, int z){
	//	int z = level->GetDepth();
	bool n = (north);
	bool e = (east);
	bool s = (south);
	bool w = (west);

	std::string a = "|Stair," + std::to_string(xpos) + "," + std::to_string(ypos) + "," + std::to_string(z) + "," + std::to_string(n) + "," + std::to_string(e) + "," + std::to_string(s) + "," + std::to_string(w) + "," + description;
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
