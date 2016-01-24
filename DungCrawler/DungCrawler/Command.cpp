#include "stdafx.h"
#include "Command.h"


Command::Command()
{

}

void Command::Init(Dungeon* dun){
	game = dun;
}

void Command::Execute(string para){
	cout << "wrong";
}

void Command::Execute(){
	cout << "also wrong";
}

bool Command::GameExist(){
	if (game->GetHero() != nullptr&& game->GetHero()->GetChamber() != nullptr){
		return true;
	}
	else {
		cout << "No game exists. Use 'start' to start a new game." << endl;
		return false;
	}
}

Command::~Command()
{
}
