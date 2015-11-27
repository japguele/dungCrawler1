#pragma once
#pragma message ("Enemyfac")

#include <unordered_map>
#include "UnitType.h"
#include "Level.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
class Enemy;
class EnemyFactory
{
public:
	EnemyFactory();
	~EnemyFactory();
	Enemy* createEnemy(UnitType,Level* level);
	Enemy* createBoss(Level* level);
	std::vector<std::string> type;
	std::vector<std::string>  teeth;
	std::vector<std::string>  find;

private:
	std::unordered_map<UnitType, Enemy> units;
};

