#pragma once
#include "Node.h"
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <iostream>

//	N = Normaal
//	H = Trap omhoog
//	C = Current position
//	. = Niet bezocht
//	~= Ingestort
//	
//	.	.	.	.	.
//
//	.	E	5	.	.
//		|	|
//	.	2 -	4 -	6	.
//		|		|
//	.	S	.	7	.
//
class HardCodedNodeDungeon {
public:
	HardCodedNodeDungeon();
	~HardCodedNodeDungeon();
	static std::pair<Node*, Node*> StartAndEndNode();
	static int GetDungeonSize(Node* startNode); //pointer?
};