#include "ChamberWeight.h"

ChamberWeight::ChamberWeight(int _weight, std::vector<Direction> _directionList, std::vector<int> _enemyHPList, std::vector<int> _amountTraps) {
	weight = _weight;
	directionList = _directionList;
	enemyHPList = _enemyHPList;
	amountTraps = _amountTraps;
}