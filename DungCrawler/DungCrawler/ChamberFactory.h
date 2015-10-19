#pragma once
#include "Chamber.h"

#include "Start.h"
#include "Stair.h"
#include <cstdlib>
#include <vector>
using namespace std;

class ChamberFactory
{
public:
	static Chamber** chambers;
	~ChamberFactory();
	static Chamber* CreateChamber(Chamber*, Direction, Level);
	ChamberFactory();
	static Start* CreateChambers(int);
	static Level* CreateLevel(int);

	
private:
	
	
};

