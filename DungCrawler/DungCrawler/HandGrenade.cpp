#include "HandGrenade.h"
using namespace std;

typedef std::multimap<Chamber*, Chamber*>::iterator mapIter;

HandGrenade::HandGrenade(std::string name, std::string description) {
	this->name = name;
	this->description = description;
}

HandGrenade::~HandGrenade() {
	//no pointers
}

void HandGrenade::UseItem(Hero* hero) {
	//get the minimum spanning tree
	//and try to destroy paths to chambers, if the chamber is in the minimum spanning tree, do not destroy the chamber

	//GetMinimumSpanningTree(hero->GetChamber());
	MakeDirectionsInaccessible(GetMinimumSpanningTree(hero->GetChamber()), hero->GetChamber());




	
}

std::map<pair<Chamber*, Direction>, Chamber*>* HandGrenade::GetMinimumSpanningTree(Chamber* startChamber) {
	//set node/vertex in tree
	std::map<pair<Chamber*, Direction>, Chamber*>* minimumSpanningTree = new std::map<pair<Chamber*, Direction>, Chamber*>();
	std::vector<Chamber*> nodeList = std::vector<Chamber*>();

	nodeList.push_back(startChamber); //starting node

	std::pair<std::pair<Chamber*, Direction>, Chamber*> pair = std::pair<std::pair<Chamber*, Direction>, Chamber*>();
	std::pair<Chamber*, Direction> chamberDirPair = std::pair<Chamber*, Direction>();
	std::map<std::pair<Chamber*, Direction>, Chamber*> nodesAndEdgesToChooseFrom = std::map<std::pair<Chamber*, Direction>, Chamber*>();
	std::map<std::pair<Chamber*, Direction>, Chamber*> blockNodesAndEdges = std::map<std::pair<Chamber*, Direction>, Chamber*>();

	//setting up directionVector
	std::vector<Direction> directionVector = std::vector<Direction>();
	directionVector.push_back(Direction::North);
	directionVector.push_back(Direction::East);
	directionVector.push_back(Direction::South);
	directionVector.push_back(Direction::West);

	bool keepLooping = true;

	//loop until we have a minimum spanning tree
	while (keepLooping) {
		for (auto currentNode : nodeList) {
			for (auto direction : directionVector) { //adjacent nodes
				if (currentNode->GetChamberInDirection(direction)) { //if adjacent node exists
					if (std::find(nodeList.begin(), nodeList.end(), currentNode->GetChamberInDirection(direction)) == nodeList.end()) { //if the adjacent node is not already in the nodeList
						chamberDirPair.first = currentNode;
						chamberDirPair.second = direction;

						pair.first = chamberDirPair; //key
						pair.second = currentNode->GetChamberInDirection(direction); //value

						if (nodesAndEdgesToChooseFrom.find(chamberDirPair) == nodesAndEdgesToChooseFrom.end() //if not already in the nodesAndEdges map
									&& blockNodesAndEdges.find(chamberDirPair) == blockNodesAndEdges.end()) { //and the blockNodesAndEdges map
							nodesAndEdgesToChooseFrom.insert(pair);
						}

					}
				}
			}
		}

		if (nodesAndEdgesToChooseFrom.empty()) {
			keepLooping = false;
			break;
		}

		pair.first = nodesAndEdgesToChooseFrom.begin()->first;
		pair.second = nodesAndEdgesToChooseFrom.begin()->second;

		int weightCurrentPair = 10;

		//check lowest weight node/edge
		for (auto currentPair : nodesAndEdgesToChooseFrom) {
			int weightLoopPair = 0;

			if (pair.second->GetEnemy())
				weightLoopPair++;
			if (pair.second->GetTrap())
				weightLoopPair++;

			if (weightLoopPair < weightCurrentPair) {
				pair = currentPair;
				weightCurrentPair = weightLoopPair;
			}
		}

		//set lowest weight node
		nodeList.push_back(pair.second);
		nodesAndEdgesToChooseFrom.erase(pair.first);
		blockNodesAndEdges.insert(pair);
		minimumSpanningTree->insert(pair);

		pair.first.first->spanningTree = true;
		pair.second->spanningTree = true;

		//repeat adding node/edge
	}

	return minimumSpanningTree;
}

void HandGrenade::MakeDirectionsInaccessible(std::map<pair<Chamber*, Direction>, Chamber*>* minimumSpanningTree, Chamber* startChamber) {
	//---BREADTH FIRST SEARCH SETTING UP---//
	std::deque<Chamber*> queue = std::deque<Chamber*>();
	std::unordered_set<Chamber*> visited = std::unordered_set<Chamber*>();
	
	//setting up directionVector
	std::vector<Direction> directionVector = std::vector<Direction>();
	directionVector.push_back(Direction::North);
	directionVector.push_back(Direction::East);
	directionVector.push_back(Direction::South);
	directionVector.push_back(Direction::West);

	std::multimap<Chamber*, Chamber*>::iterator m_it, s_it;

	std::pair<Chamber*, Direction> chamberDirPair = std::pair<Chamber*, Direction>();

	queue.push_back(startChamber); //get current chamber and start finding the stairs

	std::random_device rd; // obtain a random number from hardware
	std::mt19937 eng(rd()); // seed the generator
	std::uniform_int_distribution<> distr(10, 15); // define the range

	int range = distr(eng); // generate random number between range
	int amount = 0;

	std::map<Chamber*, Direction> removeChambers = std::map<Chamber*, Direction>();

	//keep looping until everything is dead
	while (amount <= range) {
		Chamber* chamber = queue.front(); //get first element
		visited.insert(chamber); //enqueue / push

		for (auto direction : directionVector) { //adjacent chambers
			if (chamber->GetChamberInDirection(direction)) { //check if exists
				if (std::find(visited.begin(), visited.end(), chamber->GetChamberInDirection(direction)) == visited.end() // check if in visited
						&& std::find(queue.begin(), queue.end(), chamber->GetChamberInDirection(direction)) == queue.end()) { // check if in queue
					
					chamberDirPair.first = chamber;
					chamberDirPair.second = direction;
					
					if (minimumSpanningTree->find(chamberDirPair) == minimumSpanningTree->end()) { //not in minimumSpanningTree
						removeChambers.insert(make_pair(chamber, direction));
						amount++;
					}

					queue.push_back(chamber->GetChamberInDirection(direction));
				}
			}
		}
		queue.pop_front(); //dequeue / pop

		if (!queue.empty()) {
			break;
		}
	}

	if (amount > range) {
		for (auto removeChamberPair : removeChambers) {
			removeChamberPair.first->SetInAccessibleDirection(removeChamberPair.second);
		}
	}
	else {
		std::cout << "It's too dangerous to use the Hand Grenade" << std::endl;
	}
}