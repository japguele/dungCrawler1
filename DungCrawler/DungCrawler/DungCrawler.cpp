// DungCrawler.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MainController.h"
#include "Talisman.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	//MainController* mc = new MainController();
	//delete mc;

	Talisman t = Talisman();
	t.breadthFirstSearch();

	return 0;
}

