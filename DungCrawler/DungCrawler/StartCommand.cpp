#include "stdafx.h"
#include "StartCommand.h"


StartCommand::StartCommand()
{
}

void StartCommand::Execute(){
	game->GetChamberFactory()->clean();
	game->CreateDungeon();
}

StartCommand::~StartCommand()
{
}
