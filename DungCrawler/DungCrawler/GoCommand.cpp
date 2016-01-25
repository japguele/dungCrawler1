#include "stdafx.h"
#include "GoCommand.h"

GoCommand::GoCommand()
{
	directions = unordered_map<string, Direction>({ { "north", Direction::North }, { "east", Direction::East }, { "south", Direction::South }, { "west", Direction::West }, { "up", Direction::Up }, { "down", Direction::Down } });
}
 
void GoCommand::Execute(string dir) {
	if (GameExist()){
		Chamber* currentChamber = game->GetHero()->GetChamber();
		if (CheckDirection(dir)){
			if (currentChamber->GetChamberInDirection(directions.at(dir)) != nullptr){
				if (currentChamber->DirectionIsOpen(directions.at(dir))){


					if (currentChamber->GetEnemy() == nullptr){
						if (currentChamber->GetChamberInDirection(directions.at(dir)))
							if (currentChamber->GetTrap() != nullptr){
							game->GetHero()->TakeDamage(currentChamber->GetTrap()->GetDamageValue());
							}
						cout << "I went " << dir << ".\n";
						game->GetHero()->SetCurrentChamber(currentChamber->GetChamberInDirection(directions.at(dir)));
					}
					else {
						cout << "Their is an enemy blocking yout path. you have to defaeat it before you can go further." << endl;
					}
				}
				else{
					cout << "The way is blocked by rubble" << endl;

				}
			}
			else {
				cout << "Their is no path in this direction.\n";
			}
		}
		else {
			cout << "Can you give me a real direction? (north, east, south, west)" << endl;
		}
	}
}

void GoCommand::Execute() {
	cout << "Can you also give me a direction please.\n";
}

bool GoCommand::CheckDirection(std::string dir){
	for (const auto& dire : directions) {
		if (dire.first == dir){
			return true;
		}
	}
	return false;
}

GoCommand::~GoCommand()
{
}
