#pragma once
#include "stdafx.h"
#include "Talisman.h"
#include "Chamber.h"
#include "ChamberFactory.h"
#include "Node.h"
#include <iostream>
#include <list>

Talisman::Talisman() {

}

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
void Talisman::breadthFirstSearch() {
	//temp hardcoded chamber list
	Node *startNode = new Node("STN");
	Node *node2 = new Node("N2");
	Node *endNode = new Node("END");
	Node *node4 = new Node("N4");
	Node *node5 = new Node("N5");
	Node *node6 = new Node("N6");
	Node *node7 = new Node("N7");

	startNode->setNorthNode(node2);
	node2->setSouthNode(startNode);
	node2->setNorthNode(endNode);
	endNode->setSouthNode(node2);
	node2->setEastNode(node4);
	node4->setWestNode(node2);
	node4->setNorthNode(node5);
	node5->setSouthNode(node4);
	node4->setEastNode(node6);
	node6->setWestNode(node4);
	node6->setSouthNode(node7);
	node7->setNorthNode(node7);

	//test
	startNode->printAllNodes();
	node2->printAllNodes();
	endNode->printAllNodes();
	node4->printAllNodes();
	node5->printAllNodes();
	node6->printAllNodes();
	node7->printAllNodes();

	//breadth first
	Queue Q;

	/** Keeps track of explored vertices */
	bool *explored = new bool[n + 1];

	/** Initailized all vertices as unexplored */
	for (int i = 1; i <= n; ++i)
		explored[i] = false;



	delete startNode;
	delete node2;
	delete endNode;
	delete node4;
	delete node5;
	delete node6;
	delete node7;
}