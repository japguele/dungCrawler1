#include "stdafx.h"
#include "GoCommand.h"

GoCommand::GoCommand()
{
	directions = unordered_map<string, Direction>({ { "north", Direction::North }, { "east", Direction::East }, { "south", Direction::South }, { "west", Direction::West }, { "up", Direction::Up }, { "east", Direction::Down } });
}
 
void GoCommand::Execute(string dir) {
	Chamber* currentChamber = game->GetHero()->GetChamber();
	/*Chamber currentChamber = hero.currentChamber;*/
	//afvangen of string== enum
	if (currentChamber->GetChamberInDirection(directions.at(dir)) != nullptr){
		cout << "I went " << dir <<".\n";
		game->GetHero()->SetCurrentChamber(currentChamber->GetChamberInDirection(directions.at(dir)));
		
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
