#include "stdafx.h"
#include "QuitCommand.h"


QuitCommand::QuitCommand()
{
}

void QuitCommand::Execute(){
	cout << "Are you sure you want to give up? (yes/no)";
	string input;
	cin >> input;
	if (input == "yes"){
		exit(0);
	}
}

QuitCommand::~QuitCommand()
{
}
