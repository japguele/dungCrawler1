#include "stdafx.h"
#include "LoadCommand.h"

enum loadenum{ player, dungeon };

LoadCommand::LoadCommand()
{
}

loadenum hashit(string const& inString) {
	if (inString == "player") return loadenum::player;
	if (inString == "dungeon") return loadenum::dungeon;
}

void LoadCommand::Execute(){
	cout << "Please try again and tell me what to load. ('load player'/'load dungeon')." << endl;
}

void LoadCommand::Execute(string move){
	if (hashit(move) == loadenum::player){
		cout << "Please give the name of the PLayer-save-fil: ";
		string input;
		cin >> input;
		game->LoadPlayer(input);
	}
	else if (hashit(move) == loadenum::dungeon){
		cout << "Please give a name for the Dungeon-save-fil: ";
		string input;
		cin >> input;
		game->Load(input);
	}
	else{
		cout << "Use 'load dungeon' to load the dungeon. Use 'load player' to load the player. Try again." << endl;
	}
}

LoadCommand::~LoadCommand()
{
}
