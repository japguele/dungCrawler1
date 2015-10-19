#include "stdafx.h"
#include "ChamberFactory.h"


ChamberFactory::ChamberFactory()
{
	
}
/*Chamber* ChamberFactory::CreateChamber(Chamber* chamber,Direction dir,Level level){
	if (chamber != NULL){
		//TODO RANDOM 1/100 is boss chamber
		return new Chamber(chamber, dir);
	}
	else{
		return new Start();
	}
}
Start* ChamberFactory::CreateChambers(int ammount){
	
	int levels = ammount / 15;
	
	 int v2{ rand() % (levels + 5) + levels };


	 std::vector<Level*> level(v2);
	 std::vector<Stair*> stairs(v2);    // make room for 10 integers,
	 // and initialize them to 0
	 // do something with them:
	 for (int i = 0; i<v2; ++i){
		 level[i] = CreateLevel(i);
		 stairs[i] = new Stair();
	 }
	 level[0];

	 return null;

	
}*/
Level* ChamberFactory::CreateLevel(int depth){
	return new Level(depth);
}

ChamberFactory::~ChamberFactory()
{
}
