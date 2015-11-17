#include "stdafx.h"
#include "GoCommand.h"

GoCommand::GoCommand()
{
	directions = unordered_map<string, Direction>({ { "north", Direction::North }, { "east", Direction::East }, { "south", Direction::South }, { "west", Direction::West }, { "up", Direction::Up }, { "down", Direction::Down } });
}
 
void GoCommand::Execute(string dir) {
	Chamber* currentChamber = game->GetHero()->GetChamber();
	if (currentChamber->GetChamberInDirection(directions.at(dir)) != nullptr){
		if (currentChamber->GetEnemy() == nullptr){
			cout << "I went " << dir << ".\n";
			game->GetHero()->SetCurrentChamber(currentChamber->GetChamberInDirection(directions.at(dir)));
		}
		else {
			cout << "Their is an enemy blocking yout path. you have to defaeat it before you can go further." << endl;
		}
	}
	else {
		cout << "Their is no path in this direction.\n";
	}
	
}

void GoCommand::Execute() {
	cout << "Can you also give me a direction please.\n";
}

GoCommand::~GoCommand()
{
}
