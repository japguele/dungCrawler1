#pragma once
#include "Node.h"

class Talisman
{
public:
	Talisman();
	void breadthFirstSearch();
	int breadthFirstSearchReal(Node* startNode, Node* goal);
};