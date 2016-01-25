#pragma once
#include "Command.h"
#include "Hero.h"
class SeeCommand :
	public Command
{
private:
	bool cheatmode = false;
	bool healthmode = false;
	bool spanningTreeMode = false;
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

