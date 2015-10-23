#pragma once
#include <string>
#include <array>

class Node
{
private:
	std::string m_identifier;
	Node* m_northNode;
	Node* m_eastNode;
	Node* m_southNode;
	Node* m_westNode;
	std::array<Node*, 4> adjacentNodes;

public :
	//Node(Node &northNode, Node &eastNode, Node &southNode, Node &westNode);
	Node(std::string identifier);

	std::string &getIdentifier();
	
	std::array<Node*, 4> getAdjacentNodes() const;

	Node* getNorthNode() const;
	Node* getEastNode() const;
	Node* getSouthNode() const;
	Node* getWestNode() const;

	void setNorthNode(Node *node);
	void setEastNode(Node *node);
	void setSouthNode(Node *node);
	void setWestNode(Node *node);

	void printAllNodes();
};