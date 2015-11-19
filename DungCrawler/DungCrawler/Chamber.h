#pragma once
#pragma message ("chamber")
#include "Level.h"
#include "Direction.h"
#include <string>
#include "Enemy.h"
#include <array>
#include "Trap.h"

class Chamber
{
public:
	virtual std::string GetMapIcon();
	Chamber(Level*,int,int,std::string,Enemy*,Trap*);
	virtual ~Chamber();
	virtual void SetChamberInDirection(Chamber*, Direction);
	
	
	Level* GetLevel();
	virtual Chamber* GetChamberInDirection(Direction);
	int GetXpos();
	int GetYpos();
	std::string getDescription() { return description; }

	Enemy* GetEnemy();

	bool AttackEnemy(int);

	std::array<bool, 4> GetExits();
	Level* level;
	Chamber* north;
	Chamber* east;
	Chamber* west;
	Chamber* south;
	std::array<bool, 4> exits;

	void SetVisited();
	bool GetVisited();
	Trap* GetTrap();
	void DefeatEnemy();
private:
	Enemy* enemy;
	int xpos;
	int ypos;
	std::string description;
	Trap* trap;
protected:
	bool visited;
};

