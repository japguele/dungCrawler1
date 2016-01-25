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
	virtual std::string GetMapIconCheatmode();
	virtual std::string GetMapIconSpanMode();
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
	virtual std::string Save(int x, int y, int z);
	Level* level;
	void SetInAccessibleDirection(Direction);
	Chamber* north;
	Chamber* east;
	Chamber* west;
	Chamber* south;
	std::array<bool, 4> exits;
	bool GetVisited();
	void SetVisited();
	Trap* GetTrap();
	void DefeatEnemy();

	bool spanningTree = false;

	virtual int GetWeight();
protected:
	Enemy* enemy;
	int xpos;
	int ypos;
	std::string description;
	Trap* trap;
	bool visited;
	
};

