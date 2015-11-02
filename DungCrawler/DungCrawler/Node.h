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

public :
	//Node(Node &northNode, Node &eastNode, Node &southNode, Node &westNode);
	Node(std::string identifier);

	std::string &getIdentifier();
	
	std::vector<Node*> getAdjacentNodes() const;

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