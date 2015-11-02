#include "stdafx.h"
#include "SeeCommand.h"

enum actions { backpack, self, map, chamber };

SeeCommand::SeeCommand()
{
}

void SeeCommand::Execute(){

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

void SeeCommand::printBackpack(){
	string backpack[] = game.hero.GetBackpack();
	cout << "My backpack contains:\n";
	for (int i = 0; i < backpack.length(); i++){
		if (backpack[i] != null){
			cout << "\t-" << backpack[i] << ".\n";
		}
	}
}

void SeeCommand::printSelf(){
	Hero hero = game.gethero();
	cout << "My stats are: \n";
	cout << "My level is: \n";
	cout << "I need ... more exp to level up: \n";
}

void SeeCommand::printMap(){
	// TODO
}

void SeeCommand::printRoom(){
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
	}
}

actions hashit(string const& inString) {
	if (inString == "backpack") return backpack;
	if (inString == "self") return self;
	if (inString == "map") return map;
	if (inString == "room") return room;
}

SeeCommand::~SeeCommand()
{
}
