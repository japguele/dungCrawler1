#include "stdafx.h"
#include "SaveCommand.h"

enum playerenum{player, dungeon};

SaveCommand::SaveCommand()
{
}

playerenum hashit(string const& inString) {
	if (inString == "player") return playerenum::player;
	if (inString == "dungeon") return playerenum::dungeon;
}

void SaveCommand::Execute(){
	if (GameExist()){
		cout << "Please try again and tell me what to save. ('save player'/'save dungeon')." << endl;
	}
}
void SaveCommand::Execute(string move){
	if (GameExist()){
		if (hashit(move) == playerenum::player){
			cout << "Please give a name for the PLayer-save-fil: ";
			string input;
			cin >> input;
			game->SavePlayer(input);
		}
		else if (hashit(move) == playerenum::dungeon){
			cout << "Please give a name for the Dungeon-save-fil: ";
			string input;
			cin >> input;
			game->Save(input);
		}
		else{
			cout << "Use 'save dungeon' to save the dungeon. Use 'save player' to save the player. Try again." << endl;
		}
	}
}



SaveCommand::~SaveCommand()
{
}
