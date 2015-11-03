#pragma once
#include "Level.h"
#include "Direction.h"
#include <string>



class Chamber
{
public:
	
	Chamber(Level*,int,int,std::string);
	virtual ~Chamber();
	virtual void SetChamberInDirection(Chamber*, Direction);
	

	Level* GetLevel();
	Chamber* GetChamberInDirection(Direction);
	int GetXpos();
	int GetYpos();
	std::string getDescription();
	void AttackEnemy(int);
private:
	int xpos;
	int ypos;
	std::string description;
protected:
	Level* level;
	Chamber* north;
	Chamber* east;
	Chamber* west;
	Chamber* south;
};

