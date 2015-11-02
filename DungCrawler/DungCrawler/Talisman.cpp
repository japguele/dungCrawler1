#pragma once
#include "stdafx.h"
#include "Talisman.h"
#include "Chamber.h"
#include "ChamberFactory.h"
#include <iostream>
#include <list>
#include <deque>
#include <unordered_set>
#include <unordered_map>

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
	Node *startNode = new Node("STN");
	Node *node2 = new Node("N2");
	Node *endNode = new Node("END");
	Node *node4 = new Node("N4");
	Node *node5 = new Node("N5");
	Node *node6 = new Node("N6");
	Node *node7 = new Node("N7");

	/*startNode->setNorthNode(node2);
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
	node7->setNorthNode(node6);*/

	//node 7 & endNode swap test

	startNode->setNorthNode(node2);
	node2->setSouthNode(startNode);
	node2->setNorthNode(node7); //swap
	node7->setSouthNode(node2); //swap
	node2->setEastNode(node4);
	node4->setWestNode(node2);
	node4->setNorthNode(node5);
	node5->setSouthNode(node4);
	node4->setEastNode(node6);
	node6->setWestNode(node4);
	node6->setSouthNode(endNode); //swap
	endNode->setNorthNode(node6); //swap

	//test
	startNode->printAllNodes();
	node2->printAllNodes();
	endNode->printAllNodes();
	node4->printAllNodes();
	node5->printAllNodes();
	node6->printAllNodes();
	node7->printAllNodes();

	std::cout << "Durr?" << std::endl;
	std::cout << "BFS Distance Talisman: " << breadthFirstSearchReal(startNode, endNode) << std::endl;

	delete startNode;
	delete node2;
	delete endNode;
	delete node4;
	delete node5;
	delete node6;
	delete node7;
}

int Talisman::breadthFirstSearchReal(Node* startNode, Node* goal) {
	//breadth first
	std::deque<Node*> queue = std::deque<Node*>();
	std::unordered_set<Node*> visited = std::unordered_set<Node*>();
	std::unordered_map<Node*, int> distance = std::unordered_map<Node*, int>();

	queue.push_back(startNode);
	distance[startNode] = 0;

	while (!queue.empty()) {
		Node* node = queue.front(); //get first element
		visited.insert(node); //enqueue / push
		std::cout << "current Node: " + node->getIdentifier() << std::endl;

		//for (int i = 0; i<node->getAdjacentNodes.; i++) {
		for (unsigned int i = 0; i < node->getAdjacentNodes().size(); i++) {
			std::cout << "adjacent Node: " + node->getAdjacentNodes()[i]->getIdentifier() << std::endl;
			if (std::find(visited.begin(), visited.end(), node->getAdjacentNodes()[i]) == visited.end()
					&& std::find(queue.begin(), queue.end(), node->getAdjacentNodes()[i]) == queue.end()) {
				std::cout << "not inside queue & visited" << std::endl;
				distance[node->getAdjacentNodes()[i]] = distance[node] + 1;
				if (node->getAdjacentNodes()[i] == goal) {
					return distance[node->getAdjacentNodes()[i]];
				}
				queue.push_back(node->getAdjacentNodes()[i]);
			}
		}
		queue.pop_front(); //dequeue / pop
	}

	return -1; //not found, catch -1
}