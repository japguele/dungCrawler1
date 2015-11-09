#include "HardcodedNodeDungeon.h"

HardCodedNodeDungeon::HardCodedNodeDungeon() {

}

HardCodedNodeDungeon::~HardCodedNodeDungeon() {

}

std::pair<Node*, Node*> HardCodedNodeDungeon::StartAndEndNode() {
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

	std::pair<Node*, Node*> startAndEndNode = std::pair<Node*, Node*>();
	startAndEndNode.first = startNode;
	startAndEndNode.second = endNode;
	return startAndEndNode;

	/*delete startNode;
	delete node2;
	delete endNode;
	delete node4;
	delete node5;
	delete node6;
	delete node7;*/
}