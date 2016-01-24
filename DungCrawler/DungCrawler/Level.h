#pragma once

class Level
{
public:
	Level(int);
	~Level();
	int GetDepth();
	int GetMonsterDif();
	
private:
	int Randomize();
	int depth;
	int monsterDiffeculty;
	int dropRate;
	int bossChance;

};

