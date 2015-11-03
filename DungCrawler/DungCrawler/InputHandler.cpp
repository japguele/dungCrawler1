#pragma once
#include "stdafx.h"
#include "InputHandler.h"
#include <string>
#include <iostream>
#include <sstream>

InputHandler::InputHandler(Dungeon* dun)
{
	Dungeon* dungeon = dun;
	//commands = CommandFactory(dun);
	commands = new CommandFactory(dungeon);
}

void InputHandler::Handle(string input){
	istringstream buf(input);
	istream_iterator<string> beg(buf), end;
	vector<string> arr(beg, end);
	if (commands->existingCommands(arr[0])){
		if (arr.size() == 1)
		{
			commands->GetCommand(arr[0])->Execute();
		}
		else{
			commands->GetCommand(arr[0])->Execute(arr[1]);
		}
	}
	
}

InputHandler::~InputHandler()
{
}
