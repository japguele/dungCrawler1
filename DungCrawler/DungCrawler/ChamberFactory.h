#pragma once
#pragma message ("chambefactory")
#include "EnemyFactory.h"
#include "Chamber.h"
#include "BossChamber.h"
#include "Stair.h"
#include "Array3D.h"
#include <cstdlib>
#include <vector>
#include <string>
#include <ctime>



using namespace std;

class ChamberFactory
{
public:

	Chamber** chambers;
	~ChamberFactory();
	Chamber* CreateChamber(Level*, int xpos, int ypos);
	ChamberFactory();
	Chamber* CreateChambers(int);

	void RandomChambersArround(Chamber* cham, int north, int south, int west, int east);
	Chamber* RandomChamberDirection(Chamber* cham, Direction d);

	Array3D* GetArray3D();

private:
	EnemyFactory fac;
	Array3D* ray;
	int counter;
	string light[3];
	string size[3];
	string chambertype[10];
	string objects[10];
	string objectsloc[3];




};

