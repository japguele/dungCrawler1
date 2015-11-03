#pragma once
#include "Command.h"
#include "Chamber.h"
#include "Hero.h"

class GoCommand :
	public Command
{
public:
	GoCommand();
	void Execute(string arr) override;
	void Execute() override;
	~GoCommand();
private:
	unordered_map<string, Direction> directions;
};

