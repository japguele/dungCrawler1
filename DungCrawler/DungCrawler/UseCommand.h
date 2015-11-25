#pragma once
#include "Command.h"
#include "Item.h"
#include <vector>
class UseCommand :
	public Command
{
public:
	UseCommand();
	virtual void Execute();
	virtual void Execute(string);
	~UseCommand();
};

