#pragma once
#include "Command.h"
class HelpCommand :
	public Command
{
public:
	HelpCommand();
	virtual void Execute();
	~HelpCommand();
};
