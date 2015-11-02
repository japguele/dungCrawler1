#pragma once
#include "Command.h"
class StartCommand :
	public Command
{
public:
	StartCommand();
	virtual void Execute();
	~StartCommand();
};

