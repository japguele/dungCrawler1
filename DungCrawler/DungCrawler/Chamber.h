#pragma once
#pragma message ("chamber")
#include "Level.h"
#include "Direction.h"
#include <string>
#include "Enemy.h"
#include <array>


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
	std::string getDescription() { return description; }

	Enemy* GetEnemy();

	bool AttackEnemy(int);

	std::array<bool, 4> GetExits();
	virtual std::string Save(int x, int y, int z);
private:

protected:
	Enemy* enemy;
	int xpos;
	int ypos;
	std::string description;
	Level* level;
	Chamber* north;
	Chamber* east;
	Chamber* west;
	Chamber* south;
	std::array<bool, 4> exits;
};

