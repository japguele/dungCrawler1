#pragma once
#include "stdafx.h"
#include "Talisman.h"
#include "Chamber.h"
#include "ChamberFactory.h"
#include "Node.h"
#include <iostream>

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
	Node *startNode = new Node("startNode");
	Node *node2 = new Node("node2");
	Node *endNode = new Node("endNode");
	Node *node4 = new Node("node4");
	Node *node5 = new Node("node5");
	Node *node6 = new Node("node6");
	Node *node7 = new Node("node7");

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




	delete startNode;
	delete node2;
	delete endNode;
	delete node4;
	delete node5;
	delete node6;
	delete node7;
}