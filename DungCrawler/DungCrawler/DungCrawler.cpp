// DungCrawler.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MainController.h"
#include "Talisman.h"
#include "HandGrenade.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	//MainController* mc = new MainController();
	//delete mc;

	std::pair<Node*, Node*> startAndEndNode = HardCodedNodeDungeon::StartAndEndNode();

	/*Talisman t = Talisman();
	std::cout << "BFS Distance Talisman: " << t.breadthFirstSearch(startAndEndNode.first, startAndEndNode.second) << std::endl;*/

	HandGrenade h = HandGrenade();
	h.Explosions();

	return 0;
}

