#pragma once
#include "Command.h"
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
	~SeeCommand();	
};

