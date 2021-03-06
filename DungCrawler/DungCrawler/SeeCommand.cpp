#include "stdafx.h"
#include "SeeCommand.h"

enum actions { backpack, self, map, chamber, cheatmap };

SeeCommand::SeeCommand()
{
}

void SeeCommand::Execute(){

}

actions hashit(string const& inString) {
	if (inString == "backpack") return backpack;
	if (inString == "self") return self;
	if (inString == "map") return map;
	if (inString == "chamber") return chamber;
	if (inString == "cheatmap") return cheatmap;
}

void SeeCommand::Execute(string command){
	if (GameExist()){
		switch (hashit(command)){
		case backpack:
			printBackpack();
			break;
		case self:
			printSelf();
			break;
		case map:
			printMap();
			break;
		case chamber:
			printRoom();
			break;
		case cheatmap:
			cheatmode = true;
			printMap();
			cheatmode = false;
			break;
		default:
			cout << "That is no valid action, please use: backpack/self/map/chamber";
		}
	}
}

void SeeCommand::printBackpack(){
	auto backpack = game->GetHero()->GetBackpack();

	cout << "My backpack contains:\n";
	for (int x = 0; x < backpack.size(); x++){
		cout << "-" + backpack.at(x)->GetName() << endl;
	}
}

void SeeCommand::printSelf(){
	Hero* hero = game->GetHero();
	cout << "My stats are: " << hero->GetOffense() << " offense, " << hero->GetDefense() << " defense.\n";
	cout << "I have " << hero->GetHealth() << " health left." << endl;
	cout << "My level is: " << hero->GetLevel() << "\n";
	cout << "I need " << ((hero->GetLevel() * 100) - hero->GetExperience()) << " more exp to level up: \n";
}

void SeeCommand::printMap(){
	cout << "[ ] = Undiscovered chamber" << endl;
	cout << "[O] = Empty chamber" << endl;
	cout << "[X] = You are here" << endl;
	cout << "[S] = Stair room" << endl;
	cout << "[M] = Chamber with a monster" << endl;
	cout << "[T] = Chamber with a trap" << endl;
	cout << "[B] = Chamber with a boss monster" << endl;
	cout << "- = A hallway east/west" << endl;
	cout << "| = A hallway north/south" << endl;
	size_t z = game->GetHero()->GetChamber()->GetLevel()->GetDepth();
	for (int x = 0; x < 10; x++){
		for (int y = 0; y < 10; y++){
			PrintTopLine(game->GetChamberFactory()->GetArray3D()->get(x, y, z));
		}
		cout << endl;
		for (int yy = 0; yy < 10; yy++){
			PrintTopHallwayLine(game->GetChamberFactory()->GetArray3D()->get(x, yy, z));
		}
		cout << endl;
	}
	
}

void SeeCommand::PrintTopLine(Chamber* chamber){
	if (chamber != nullptr){
		if (game->GetHero()->GetChamber() == chamber){
			cout << "[X]";
		}
		else {
			if (cheatmode){
				cout << "[" << chamber->GetMapIconCheatmode() << "]";
			}
			else {
				cout << "["<<chamber->GetMapIcon()<<"]";
			}
		}
		if (!cheatmode){
			if (chamber->GetChamberInDirection(Direction::East) && chamber->GetChamberInDirection(Direction::East)->GetVisited()){
				cout << "-";
			}
			else {
				cout << " ";
			}
		}
		else {
			if (chamber->GetChamberInDirection(Direction::East)){
				cout << "-";
			}
			else {
				cout << " ";
			}
		}
	}
	else {
		cout << "[ ] ";
	}
}

void SeeCommand::PrintTopHallwayLine(Chamber* chamber){
	if (chamber != nullptr){
		if (!cheatmode){
			if (chamber->GetChamberInDirection(Direction::South) && chamber->GetChamberInDirection(Direction::South)->GetVisited()){
				cout << " |  ";
			}
			else {
				cout << "    ";
			}
		}
		else {
			if (chamber->GetChamberInDirection(Direction::South)){
				cout << " |  ";
			}
			else {
				cout << "    ";
			}
		}
	}
	else {
		cout << "    ";
	}
}

void SeeCommand::printRoom(){
	string description = game->GetHero()->GetChamber()->getDescription();
	Enemy* enemy = game->GetHero()->GetChamber()->GetEnemy();
	Trap* trap = game->GetHero()->GetChamber()->GetTrap();
	Level* level = game->GetHero()->GetChamber()->GetLevel();
	Chamber* chamber = game->GetHero()->GetChamber();
	array<bool, 4> exits = chamber->GetExits();
	if (description != ""){
		cout << "The description of this chamber is: " << description << ".\n";
	}
	if (enemy != nullptr){
		cout << "This chamber contains the following enemy: " << enemy->GetDisc() << ".\n";
	}
	else {
		cout << "This chamber contains no enemy.\n";
	}
	if (trap != nullptr){
		cout << "This room contains the following trap: " << trap->GetDescription() << ".\n";
	}
	else {
		cout << "This chamber contains no trap.\n";
	}
	if (level != nullptr){
		cout << "This chamber is on level: " << level->GetDepth() << ".\n";
	}
	if (!exits.empty()){
		cout << "This chamber has exits in the following directions: ";
		if (chamber->GetChamberInDirection(Direction::North) != nullptr){
			cout << "North, ";
		}
		if (chamber->GetChamberInDirection(Direction::East) != nullptr){
			cout << "East, ";
		}
		if (chamber->GetChamberInDirection(Direction::South) != nullptr){
			cout << "South, ";
		}
		if (chamber->GetChamberInDirection(Direction::West) != nullptr){
			cout << "West, ";
		}
		cout << endl;
	}
	else{
		cout << "Somehow this Chamber has no exits." << endl;
	}
}

SeeCommand::~SeeCommand()
{
}
