#pragma once
#include "Unit.h"
#include "item.h"
#include <unordered_map>
#include <iostream>
#include "Chamber.h"

class Hero :
	public Unit
{
public:
	Hero();
	Hero(string);
	~Hero();
	void AddItem(Item*);
	void LevelUp();
	void GainExp(int);
	void DrinkPotion(int);
	int GetExperience();
	Chamber* GetChamber();
	void Attack();
	void Magic();
	void RunAway();
	void SetCurrentChamber(Chamber*);
private:
	unordered_map<string, Item*> backpack;
	int experience;
	string name;
	Chamber* currentChamber;

};

