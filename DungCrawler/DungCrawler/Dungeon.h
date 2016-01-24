#pragma once

#include "ChamberFactory.h"
#include "Hero.h"

class Dungeon
{
public:
	Dungeon(int);
	~Dungeon();
	Hero* GetHero();
	ChamberFactory* GetChamberFactory();
	void Save(std::string _name);
	void Load(std::string _name);
	void SavePlayer(std::string _name);
	void LoadPlayer(std::string _name);
	void CreateDungeon();


private:
	ChamberFactory* cf;
	Chamber* startChamber;
	Hero* hero;
	int chambers;
};

