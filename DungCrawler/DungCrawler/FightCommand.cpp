#include "stdafx.h"
#include "FightCommand.h"

enum fightMoves{ attack, magic, run /*,item*/ };

FightCommand::FightCommand()
{
}

void FightCommand::Execute(){
	cout << "Please tell me how to fight.\n";
}

fightMoves hashit(string const& inString) {
	if (inString == "attack") return attack;
	if (inString == "magic") return magic;
	if (inString == "run") return run;
	//if (inString == "item") return item;
}

void FightCommand::Execute(string move){
	fightMoves fightMove = hashit(move);
	switch (fightMove){
	case attack:
		game->GetHero()->Attack();
		break;
	case magic:
		game->GetHero()->Magic();
		break;
	case run:
		game->GetHero()->RunAway();
		break;
	//case item:
	default:
		cout << "That is no valid move, please use: attack/magic/run";
		break;
	}
}

FightCommand::~FightCommand()
{
}
