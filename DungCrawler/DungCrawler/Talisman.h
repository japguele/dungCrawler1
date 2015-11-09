#pragma once
#include "Node.h"
#include "HardcodedNodeDungeon.h"
#include "Chamber.h"
#include "ChamberFactory.h"
#include <iostream>
#include <list>
#include <deque>
#include <unordered_set>
#include <unordered_map>

class Talisman
{
public:
	Talisman();
	//void breadthFirstSearch();
	int breadthFirstSearch(Node* startNode, Node* goal);
};