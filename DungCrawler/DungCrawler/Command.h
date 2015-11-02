#pragma once
#include <string>
#include <iostream>
class Command
{
public:
	Command();
	virtual void Execute();
	virtual void Execute(string para);
	virtual ~Command();
};

