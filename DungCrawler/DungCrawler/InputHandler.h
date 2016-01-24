#pragma once
#include "stdafx.h"
#include <string>
#include "CommandFactory.h"
#include <stdio.h>

class InputHandler
{
public:
	InputHandler();
	InputHandler(Dungeon*);	
	void Handle(string input);
	~InputHandler();
private:
	CommandFactory* commands;
};

