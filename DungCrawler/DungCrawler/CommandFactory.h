#pragma once
#include "stdafx.h"
#include <unordered_map>
#include "Command.h"
#include "FightCommand.h"
#include "GoCommand.h"
#include "HelpCommand.h"
#include "LoadCommand.h"
#include "QuitCommand.h"
#include "SaveCommand.h"
#include "SeeCommand.h"
#include "StartCommand.h"
#include "UseCommand.h"
class CommandFactory
{
public:
	CommandFactory();
	CommandFactory(Dungeon*);
	Command* GetCommand(string);
	bool existingCommands(string);
	~CommandFactory();
private:
	unordered_map<string, Command*> commands;
};

