#include "stdafx.h"
#include "GoCommand.h"

GoCommand::GoCommand()
{
}
 
void GoCommand::Execute(string dir) {
	/*Chamber currentChamber = hero.currentChamber;*/
	if (/*currentChamber.dir != null*/true){
		//player.currentchamber = currentChamber.arr
		cout << "I went " << dir <<".\n";
	}
	else {
		cout << "Their is no path in this direction.\n";
	}
	
}

void GoCommand::Execute() {
	cout << "Can you also give me a direction please.\n";
}

GoCommand::~GoCommand()
{
}
