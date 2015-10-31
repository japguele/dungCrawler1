#include "stdafx.h"
#include "FightCommand.h"

enum fightMoves{ attack, magic, run, /*item*/ };

FightCommand::FightCommand()
{
}

void FightCommand::Execute(){
	cout << "Please tell me how to fight.\n";
}

void FightCommand::Execute(string move){
	string fightMove = move;
	switch (hashit(move)){
	case attack:
		game.Attack();
		break;
	case magic:
		game.Magic();
		break;
	case run:
		game.Run();
		break;
	//case item:
	default:
		cout << "That is no valid move, please use: attack/magic/run";
		break;
	}
}

fightMoves hashit(string const& inString) {
	if (inString == "attack") return attack;
	if (inString == "magic") return magic;
	if (inString == "run") return run;
	//if (inString == "item") return room;
}

FightCommand::~FightCommand()
{
}
