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
