#include "stdafx.h"
#include "BossChamber.h"




BossChamber::BossChamber(Level* lvl, int x, int y,Enemy* en) : Chamber(lvl, x, y,"boss chamber", en, nullptr)
{
}

std::string BossChamber::Save(int x, int y, int z){
	//	int z = level->GetDepth();
	bool n = (north);
	bool e = (east);
	bool s = (south);
	bool w = (west);

	std::string a = "|BossChamber," + std::to_string(xpos) + "," + std::to_string(ypos) + "," + std::to_string(z) + "," + std::to_string(n) + "," + std::to_string(e) + "," + std::to_string(s) + "," + std::to_string(w) + "," + description;
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

BossChamber::~BossChamber()
{
}
