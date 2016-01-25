#pragma once
#include "stdafx.h"
#include "Direction.h"

#include <vector>

class ChamberWeight {
public:
	ChamberWeight(int weight, std::vector<Direction> directionList, std::vector<int> enemyHPList, int amountTraps);

	int weight;
	std::vector<Direction> directionList;
	std::vector<int> enemyHPList;
	int amountTraps;
};