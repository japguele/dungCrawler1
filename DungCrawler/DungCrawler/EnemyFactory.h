#pragma once
#pragma message ("Enemyfac")

#include <unordered_map>
#include "UnitType.h"
#include "Level.h"
#include <string>
class Enemy;
class EnemyFactory
{
public:
	EnemyFactory();
	~EnemyFactory();
	Enemy* createEnemy(UnitType,Level* level);
	std::string type[5];
	std::string teeth[3];
	std::string find[3];

private:
	std::unordered_map<UnitType, Enemy> units;
};

