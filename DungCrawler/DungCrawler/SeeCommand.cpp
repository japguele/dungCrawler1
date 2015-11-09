#include "stdafx.h"
#include "SeeCommand.h"

enum actions { backpack, self, map, chamber };

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
}

void SeeCommand::Execute(string command){
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
	default:
		cout << "That is no valid action, please use: backpack/self/map/chamber";
	}
}

void SeeCommand::printBackpack(){/*
	string backpack[] = game->GetHero()->GetBackpack();

	cout << "My backpack contains:\n";
	for (int i = 0; i < backpack.length(); i++){
		if (backpack[i] != null){
			cout << "\t-" << backpack[i] << ".\n";
		}
	}*/
}

void SeeCommand::printSelf(){
	Hero* hero = game->GetHero();
	cout << "My stats are: " << hero->GetOffense() << " offense, " << hero->GetDefense() << " defense.\n";
	cout << "My level is: " << hero->GetLevel() << "\n";
	cout << "I need "<< (100 - hero->GetExperience())<<" more exp to level up: \n";
}

void SeeCommand::printMap(){
	//
}

void SeeCommand::printRoom(){/*
	string layout = game.currentChamber.GetLayout();
	string description = game.currentChamber.GetDescription();
	string enemy = game.currentChamber.GetEnemy();
	string trap = game.currentChamber.GetTrap();
	string level = game.currentChamber.GetLevel();
	if (layout != null){
		cout << "The layout of this chamber is: " << layout <<".\n";
	}
	if (description != null){
		cout << "The description of this chamber is: " << description << ".\n";
	}
	if (enemy != null){
		cout << "This chamber contains the following enemy: " << enemy << ".\n";
	}
	else {
		cout << "This chamber contains no enemy.\n";
	}
	if (trap != null){
		cout << "This room con1tains the following trap: " << trap << ".\n";
	}
	else {
		cout << "This chamber contains no trap.\n";
	}
	if (level != null){
		cout << "This chamber is on level: " << level << ".\n";
	}*/
}

SeeCommand::~SeeCommand()
{
}
