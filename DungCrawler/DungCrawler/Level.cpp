#include "stdafx.h"
#include "Level.h"
#include <cstdlib>


Level::Level(int depth1)
{
	depth = depth1;
	
	
	
	monsterDiffeculty = Randomize();
	dropRate = Randomize();
	bossChance = Randomize();
}
int Level::Randomize(){
	return rand() % (depth + 2) + depth;
}


Level::~Level()
{
}
int Level::GetDepth(){
	return depth;
}