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
	Hero(string n, int _health, int _level, int _off, int _def, int _exp, vector<Item*> _backpack);
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
	string SavePlayer();
	vector<Item*> GetBackpack();

private:
	vector<Item*> backpack;
	int experience;
	string name;
	Chamber* currentChamber;
	Chamber* previousChamber;
};

