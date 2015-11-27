#include "stdafx.h"
#include "LoadCommand.h"


LoadCommand::LoadCommand()
{
}

void LoadCommand::Execute(){
	cout << "ERRRO:::::Please give a name of the the save-file next time.";
}

void LoadCommand::Execute(string move){
	cout << "Please give a name of the save-file.";
	string input;
	cin >> input;
	game->Load(input);
}

LoadCommand::~LoadCommand()
{
}
