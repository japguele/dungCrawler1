#pragma once
#include "Talisman.h"

Talisman::Talisman() {

}



int Talisman::breadthFirstSearch(Node* startNode, Node* goal) {
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