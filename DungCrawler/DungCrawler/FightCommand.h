#pragma once
#include "Command.h"
class FightCommand :
	public Command
{
public:
	FightCommand();
	virtual void Execute();
	~FightCommand();
};

