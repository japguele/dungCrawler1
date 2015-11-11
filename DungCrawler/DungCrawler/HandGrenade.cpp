#include "HandGrenade.h"

HandGrenade::HandGrenade() {

}

HandGrenade::~HandGrenade() {

}

void HandGrenade::Explosions() {
	//dungeon
	std::pair<Node*, Node*> dungeonStartingNode = HardCodedNodeDungeon::StartAndEndNode();

	GetMinimumSpanningTree(dungeonStartingNode.first);
}

//prim's algorithm
std::multimap<Node*, Node*>* HandGrenade::GetMinimumSpanningTree(Node* startNode) {
	//get random node, will fix later

	//set node/vertex in tree
	std::multimap<Node*, Node*>* minimumSpanningTree = new std::multimap<Node*, Node*>();
	std::vector<Node*> nodeList = std::vector<Node*>();

	nodeList.push_back(startNode); //starting node

	std::pair<Node*, Node*> pair = std::pair<Node*, Node*>();
	std::multimap<Node*, Node*> nodesAndEdgesToChooseFrom = std::multimap<Node*, Node*>();

	int dungeonSize = HardCodedNodeDungeon::GetDungeonSize(startNode); //test

	//loop until we have a minimum spanning tree
	while (nodeList.size() < dungeonSize) {
		for (auto currentNode : nodeList) {
			for (auto adjacentNode : currentNode->GetAdjacentNodes()) {
				pair.first = adjacentNode; //key
				pair.second = currentNode; //value
				nodesAndEdgesToChooseFrom.insert(pair); //might not work cause not pointer
			}
		}

		//just in case
		pair.first = nullptr;
		pair.second = nullptr;

		pair.first = nodesAndEdgesToChooseFrom.begin()->first;
		pair.second = nodesAndEdgesToChooseFrom.begin()->second;

		//check lowest weight node/edge
		for (auto currentPair : nodesAndEdgesToChooseFrom) {
			if (std::find(nodeList.begin(), nodeList.end(), currentPair.first) != nodeList.end()) {
				/*contains node*/
				//don't do stuff
			}
			else {
				/*does not contain node*/
				if (pair.second->GetWeight() > currentPair.first->GetWeight()) {
					pair = currentPair;
				}
			}
		}
		//set lowest weight node
		nodeList.push_back(pair.first);
		minimumSpanningTree->insert(pair);

		//just in case
		pair.first = nullptr;
		pair.second = nullptr;
		nodesAndEdgesToChooseFrom.clear();
	}

	return minimumSpanningTree;
}