#pragma once
#include "stdafx.h"
#include "Talisman.h"
#include "Chamber.h"
#include "ChamberFactory.h"
#include "Node.h"

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
//	.	H	N	.	.
//		|	|
//	.	N -	N -	N	.
//		|		|
//	.	C	.	N	.
//
void breadthFirstSearch() {
	//temp hardcoded chamber list
	Node *startNode = new Node();
	Node *node2 = new Node();
	Node *endNode = new Node();
	Node *node4 = new Node();
	Node *node5 = new Node();
	Node *node6 = new Node();
	Node *node7 = new Node();

	startNode->setNorthNode(node2);
	node2->setSouthNode(startNode);
	node2->setNorthNode(endNode);
	endNode->setSouthNode(node2);
	node2->setEastNode(node4);
	node4->setNorthNode(node5);
	node5->setSouthNode(node4);
	node4->setEastNode(node6);
	node6->setWestNode(node4);
	node6->setSouthNode(node7);
	node7->setNorthNode(node7);

	//breadth first




	delete startNode;
	delete node2;
	delete endNode;
	delete node4;
	delete node5;
	delete node6;
	delete node7;
}