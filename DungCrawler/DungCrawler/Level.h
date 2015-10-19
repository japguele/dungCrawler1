#pragma once
class Level
{
public:
	Level(int);
	~Level();
private:
	int Randomize();
	int depth;
	int monsterDiffeculty;
	int dropRate;
	int bossChance;

};

