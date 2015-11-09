#pragma once
#pragma message ("chamber")
#include "Level.h"
#include "Direction.h"
#include <string>
#include "Enemy.h"



class Chamber
{
public:
	
	Chamber(Level*,int,int,std::string,Enemy*);
	virtual ~Chamber();
	virtual void SetChamberInDirection(Chamber*, Direction);
	
	
	Level* GetLevel();
	Chamber* GetChamberInDirection(Direction);
	int GetXpos();
	int GetYpos();
	std::string getDescription();

	Enemy* GetEnemy();

	void AttackEnemy(int);
private:
	Enemy* enemy;
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

