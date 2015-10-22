#pragma once
#include "Command.h"

class GoCommand :
	public Command
{
public:
	int test;
	GoCommand();
	void Execute(string arr) override;
	void Execute() override;
	~GoCommand();
};

