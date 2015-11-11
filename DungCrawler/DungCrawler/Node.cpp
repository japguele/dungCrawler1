#pragma once
#include "Node.h"
#include "stdafx.h"
#include <iostream>
#include <string>

//Node::Node(Node &northNode, Node &eastNode, Node &southNode, Node &westNode) {
//	m_northNode = &northNode;
//	m_eastNode = &eastNode;
//	m_southNode = &southNode;
//	m_westNode = &westNode;
//}

Node::Node(std::string new_identifier, int* newWeight) {
	m_identifier = new_identifier;
	weight = newWeight;
}

void Node::PrintAllNodes() {
	std::cout << m_identifier+"\n";

	if (m_northNode != nullptr) {
		std::cout << "cNorth ";
		std::cout << "id: "+m_northNode->GetIdentifier() + "\n";
	}
	if (m_eastNode != nullptr) {
		std::cout << "cEast ";
		std::cout << "id: " + m_eastNode->GetIdentifier() + "\n";
	}
	if (m_southNode != nullptr) {
		std::cout << "cSouth ";
		std::cout << "id: " + m_southNode->GetIdentifier() + "\n";
	}
	if (m_westNode != nullptr) {
		std::cout << "cWest ";
		std::cout << "id: " + m_westNode->GetIdentifier() + "\n";
	}

	std::cout << "\n";
}

void Node::SetNorthNode(Node *node) {
	m_northNode = node;
	adjacentNodes.push_back(node);
	//adjacentNodes[0] = node;
}
void Node::SetEastNode(Node *node) {
	m_eastNode = node;
	adjacentNodes.push_back(node);
	//adjacentNodes[1] = node;
}
void Node::SetSouthNode(Node *node) {
	m_southNode = node;
	adjacentNodes.push_back(node);
	//adjacentNodes[2] = node;
}
void Node::SetWestNode(Node *node) {
	m_westNode = node;
	adjacentNodes.push_back(node);
	//adjacentNodes[3] = node;
}

std::vector<Node*> Node::GetAdjacentNodes() const {
	return adjacentNodes;
}

Node* Node::GetNorthNode() const {
	return m_northNode;
}
Node* Node::GetEastNode() const {
	return m_eastNode;
}
Node* Node::GetSouthNode() const {
	return m_southNode;
}
Node* Node::GetWestNode() const {
	return m_westNode;
}

std::string &Node::GetIdentifier() {
	return m_identifier;
}

int* Node::GetWeight() const {
	return weight;
}