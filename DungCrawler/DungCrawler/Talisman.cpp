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
		std::cout << "current Node: " + node->GetIdentifier() << std::endl;

		//for (int i = 0; i<node->getAdjacentNodes.; i++) {
		for (unsigned int i = 0; i < node->GetAdjacentNodes().size(); i++) {
			std::cout << "adjacent Node: " + node->GetAdjacentNodes()[i]->GetIdentifier() << std::endl;
			if (std::find(visited.begin(), visited.end(), node->GetAdjacentNodes()[i]) == visited.end()
					&& std::find(queue.begin(), queue.end(), node->GetAdjacentNodes()[i]) == queue.end()) {
				std::cout << "not inside queue & visited" << std::endl;
				distance[node->GetAdjacentNodes()[i]] = distance[node] + 1;
				if (node->GetAdjacentNodes()[i] == goal) {
					return distance[node->GetAdjacentNodes()[i]];
				}
				queue.push_back(node->GetAdjacentNodes()[i]);
			}
		}
		queue.pop_front(); //dequeue / pop
	}

	return -1; //not found, catch -1
}