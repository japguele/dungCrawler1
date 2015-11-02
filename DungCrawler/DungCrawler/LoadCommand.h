#pragma once
#include "Command.h"
class LoadCommand :
	public Command
{
public:
	LoadCommand();
	virtual void Execute();
	~LoadCommand();
};

