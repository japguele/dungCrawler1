#pragma once
#include "stdafx.h" //prevent errors

#include "Item.h" // derive from

#include "Chamber.h"
#include "Hero.h"
#include <map>
#include <random>

#include <list>
#include <deque>
#include <unordered_set>
#include <unordered_map>

class HandGrenade : public Item {

public:
	HandGrenade(std::string name, std::string description);
	~HandGrenade();
	void UseItem(Hero*); //override sort of

private:
	std::map<pair<Chamber*, Direction>, Chamber*>* GetMinimumSpanningTree(Chamber* startChamber);
	void MakeDirectionsInaccessible(std::map<pair<Chamber*, Direction>, Chamber*>* minimumSpanningTree, Chamber* startChamber);
};