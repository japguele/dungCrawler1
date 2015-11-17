#pragma once
#include "Command.h"
#include "Hero.h"
class SeeCommand :
	public Command
{
public:
	SeeCommand();
	virtual void Execute(string);
	virtual void Execute();
	void printBackpack();
	void printSelf();
	void printMap();
	void printRoom();
	void PrintTopLine(Chamber* chamber);
	void PrintTopHallwayLine(Chamber* chamber);
	~SeeCommand();	
};
