#include "stdafx.h"
#include "HelpCommand.h"


HelpCommand::HelpCommand()
{
}

void HelpCommand::Execute(){
	cout << "Let me tell you to what commands I listen to\n";
	cout << "\t-go {direction}\n";
	cout << "\t-see {backpack/self/map/chamber}\n";
	cout << "\t-use {item}\n";
	cout << "\t-fight {attack/magic/run/item}\n";
	cout << "\t-start -> start a new game\n";
	cout << "\t-quit\ -> quit the gamen";
	cout << "\t-help\n";
	cout << "\t-save\n";
	cout << "\t-load\n";
}


HelpCommand::~HelpCommand()
{
}
