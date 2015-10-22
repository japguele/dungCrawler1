#pragma once
#include "Command.h"
class SaveCommand :
	public Command
{
public:
	SaveCommand();
	virtual void Execute();
	~SaveCommand();
};

