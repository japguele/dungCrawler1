#pragma once
#include "Command.h"
class UseCommand :
	public Command
{
public:
	UseCommand();
	virtual void Execute();
	~UseCommand();
};

