#pragma once
#include <string>
#include <vector>

class Node
{
private:
	std::string m_identifier;
	Node* m_northNode;
	Node* m_eastNode;
	Node* m_southNode;
	Node* m_westNode;
	std::vector<Node*> adjacentNodes;
	int* weight;

public :
	//Node(Node &northNode, Node &eastNode, Node &southNode, Node &westNode);
	Node(std::string identifier, int* newWeight);

	std::string &GetIdentifier();
	
	std::vector<Node*> GetAdjacentNodes() const;

	Node* GetNorthNode() const;
	Node* GetEastNode() const;
	Node* GetSouthNode() const;
	Node* GetWestNode() const;

	void SetNorthNode(Node *node);
	void SetEastNode(Node *node);
	void SetSouthNode(Node *node);
	void SetWestNode(Node *node);

	void PrintAllNodes();

	int* GetWeight() const;
};