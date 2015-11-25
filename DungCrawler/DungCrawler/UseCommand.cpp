#include "stdafx.h"
#include "UseCommand.h"
#include <vector>
#include "Item.h"

UseCommand::UseCommand()
{
}

void UseCommand::Execute(){

}

void UseCommand::Execute(string use){
	auto backpack = game->GetHero()->GetBackpack();
	for (int x = 0; x < backpack.size(); x++){
		if (backpack.at(x)->GetName()== use){
			backpack.at(x)->UseItem(game->GetHero());
			backpack.erase(backpack.begin()+x);
			break;
		}
	}
}

UseCommand::~UseCommand()
{
}
