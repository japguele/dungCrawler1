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
	std::pair<Node*, Node*> startAndEndNode = HardCodedNodeDungeon::StartAndEndNode();
	std::cout << "BFS Distance Talisman: " << t.breadthFirstSearch(startAndEndNode.first, startAndEndNode.second) << std::endl;

	return 0;
}

