#include "HardcodedNodeDungeon.h"

HardCodedNodeDungeon::HardCodedNodeDungeon() {

}

HardCodedNodeDungeon::~HardCodedNodeDungeon() {

}

//	N = Normaal
//	H = Trap omhoog
//	C = Current position
//	. = Niet bezocht
//	~= Ingestort
//	
//	.	.	.	.	.
//
//	.	E - 5	.	.
//		|	|
//	.	2 -	4 -	6	.
//		|		|
//	.	S	.	7	.
//
std::pair<Node*, Node*> HardCodedNodeDungeon::StartAndEndNode() {
	int* w1 = new int;
	int* w2 = new int;
	int* w3 = new int;
	int* w4 = new int;
	int* w5 = new int;
	int* w6 = new int;
	int* w7 = new int;

	*w1 = 1;
	*w2 = 1;
	*w3 = 1;
	*w4 = 3;
	*w5 = 1;
	*w6 = 2;
	*w7 = 1;
	
	Node *startNode = new Node("STN", w1);
	Node *node2 = new Node("N2", w2);
	Node *endNode = new Node("END", w3);
	Node *node4 = new Node("N4", w4);
	Node *node5 = new Node("N5", w5);
	Node *node6 = new Node("N6", w6);
	Node *node7 = new Node("N7", w7);

	startNode->SetNorthNode(node2);
	node2->SetSouthNode(startNode);
	node2->SetNorthNode(endNode);
	endNode->SetSouthNode(node2);
	endNode->SetWestNode(node5);
	node5->SetEastNode(endNode);
	node2->SetEastNode(node4);
	node4->SetWestNode(node2);
	node4->SetNorthNode(node5);
	node5->SetSouthNode(node4);
	node4->SetEastNode(node6);
	node6->SetWestNode(node4);
	node6->SetSouthNode(node7);
	node7->SetNorthNode(node6);

	//node 7 & endNode swap test

	//startNode->SetNorthNode(node2);
	//node2->SetSouthNode(startNode);
	//node2->SetNorthNode(node7); //swap
	//node7->SetSouthNode(node2); //swap
	//node7->SetEastNode(node5); //swap
	//node5->SetWestNode(node7); //swap
	//node2->SetEastNode(node4);
	//node4->SetWestNode(node2);
	//node4->SetNorthNode(node5);
	//node5->SetSouthNode(node4);
	//node4->SetEastNode(node6);
	//node6->SetWestNode(node4);
	//node6->SetSouthNode(endNode); //swap
	//endNode->SetNorthNode(node6); //swap

	//test
	startNode->PrintAllNodes();
	node2->PrintAllNodes();
	endNode->PrintAllNodes();
	node4->PrintAllNodes();
	node5->PrintAllNodes();
	node6->PrintAllNodes();
	node7->PrintAllNodes();

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

int HardCodedNodeDungeon::GetDungeonSize(Node* startNode) {
	//breadth first
	std::deque<Node*> queue = std::deque<Node*>();
	std::unordered_set<Node*> visited = std::unordered_set<Node*>();

	queue.push_back(startNode);

	while (!queue.empty()) {
		Node* node = queue.front(); //get first element
		visited.insert(node); //enqueue / push
		std::cout << "current Node: " + node->GetIdentifier() << std::endl;

		for (unsigned int i = 0; i < node->GetAdjacentNodes().size(); i++) {
			std::cout << "adjacent Node: " + node->GetAdjacentNodes()[i]->GetIdentifier() << std::endl;
			if (std::find(visited.begin(), visited.end(), node->GetAdjacentNodes()[i]) == visited.end()
				&& std::find(queue.begin(), queue.end(), node->GetAdjacentNodes()[i]) == queue.end()) {
				std::cout << "not inside queue & visited" << std::endl;
				queue.push_back(node->GetAdjacentNodes()[i]);
			}
		}
		queue.pop_front(); //dequeue / pop
	}

	return visited.size();
}