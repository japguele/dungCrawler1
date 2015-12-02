#pragma once
#include <string>
#include <iostream>
#include "Dungeon.h"
class Command
{
public:
	Dungeon* game;
	void Init(Dungeon*);
	Command();
	virtual void Execute();
	virtual void Execute(string para);
	virtual ~Command();
	virtual bool GameExist();
};

