#include "stdafx.h"
#include "CommandFactory.h"
#include <iostream>

CommandFactory::CommandFactory(){
	cout << "error";
}

CommandFactory::CommandFactory(Dungeon* dun)
{
	commands = unordered_map<string, Command*>{
		{ "fight", new FightCommand() },
		{ "go", new GoCommand() },
		{ "help", new HelpCommand() },
		{ "load", new LoadCommand() },
		{ "quit", new QuitCommand() },
		{ "save", new SaveCommand() },
		{ "see", new SeeCommand() },
		{ "start", new StartCommand() },
		{ "use", new UseCommand() }
	};
	for (auto it = commands.begin(); it != commands.end(); it++){
		Command* tempCommand = it->second;
		tempCommand->Init(dun);
	}
}

bool CommandFactory::existingCommands(string input){
	try{
		commands.at(input);
		return true;
	}
	catch (out_of_range) {
		cout << "I don't know that.\n";
		return false;
	}
}

Command* CommandFactory::GetCommand(string stringCommand){
	try{
		Command* temp = commands.at(stringCommand);
		return temp;
	}
	catch (out_of_range) {
		cout << "I don't know that.\n";
	}
}

CommandFactory::~CommandFactory()
{
	//itereer door commands array, elk element delete
}
