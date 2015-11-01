#pragma once

class Level
{
public:
	Level(int);
	~Level();
	int GetDepth();
private:
	int Randomize();
	int depth;
	int monsterDiffeculty;
	int dropRate;
	int bossChance;

};

