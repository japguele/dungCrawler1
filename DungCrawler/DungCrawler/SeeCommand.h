#pragma once
#include "Command.h"
class SeeCommand :
	public Command
{
public:
	SeeCommand();
	virtual void Execute();
	~SeeCommand();
};

