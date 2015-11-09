#pragma once
#pragma message ("Enemyfac")
#include "Enemy.h"
#include <unordered_map>
#include "UnitType.h"
#include "Level.h"
class EnemyFactory
{
public:
	EnemyFactory();
	~EnemyFactory();
	Enemy* createEnemy(UnitType,Level* level);
	string type[5];
	string teeth[3];
	string find[3];

private:
	unordered_map<UnitType, Enemy> units;
};

