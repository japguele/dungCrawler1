#pragma once
#include "Command.h"
class QuitCommand :
	public Command
{
public:
	QuitCommand();
	virtual void Execute();
	~QuitCommand();
};

