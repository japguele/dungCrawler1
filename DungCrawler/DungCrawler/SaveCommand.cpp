#include "stdafx.h"
#include "SaveCommand.h"


SaveCommand::SaveCommand()
{
}

void SaveCommand::Execute(){
	cout << "ERROR::::::::Please give a name for the the save-file next time.";
}
void SaveCommand::Execute(string move){
	cout << "Please give a name for the save-file.";
	string input;
	cin >> input;
	game->Save(input);
}

SaveCommand::~SaveCommand()
{
}
