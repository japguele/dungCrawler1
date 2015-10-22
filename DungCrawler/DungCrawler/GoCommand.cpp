#include "stdafx.h"
#include "GoCommand.h"

GoCommand::GoCommand()
{
	test = 50;
}
 
void GoCommand::Execute(string arr) {
	string param = arr;
	cout << "I went " << arr <<"\n";
}

void GoCommand::Execute() {
	cout << "Can you also give me a direction please.\n";
}

GoCommand::~GoCommand()
{
}
