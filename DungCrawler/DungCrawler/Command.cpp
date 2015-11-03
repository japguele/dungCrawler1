#include "stdafx.h"
#include "Command.h"


Command::Command()
{

}

void Command::Init(Dungeon* dun){
	game = dun;
}

void Command::Execute(string para){
	cout << "wrong";
}

void Command::Execute(){
	cout << "also wrong";
}

Command::~Command()
{
}
