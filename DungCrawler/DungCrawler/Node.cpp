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

Node::Node(std::string new_identifier) {
	m_identifier = new_identifier;
}

void Node::printAllNodes() {
	std::cout << m_identifier+"\n";

	if (m_northNode != nullptr) {
		std::cout << "cNorth ";
		std::cout << "id: "+m_northNode->getIdentifier() + "\n";
	}
	if (m_eastNode != nullptr) {
		std::cout << "cEast ";
		std::cout << "id: " + m_eastNode->getIdentifier() + "\n";
	}
	if (m_southNode != nullptr) {
		std::cout << "cSouth ";
		std::cout << "id: " + m_southNode->getIdentifier() + "\n";
	}
	if (m_westNode != nullptr) {
		std::cout << "cWest ";
		std::cout << "id: " + m_westNode->getIdentifier() + "\n";
	}

	std::cout << "\n";
}

void Node::setNorthNode(Node *node) {
	m_northNode = node;
	adjacentNodes.push_back(node);
	//adjacentNodes[0] = node;
}
void Node::setEastNode(Node *node) {
	m_eastNode = node;
	adjacentNodes.push_back(node);
	//adjacentNodes[1] = node;
}
void Node::setSouthNode(Node *node) {
	m_southNode = node;
	adjacentNodes.push_back(node);
	//adjacentNodes[2] = node;
}
void Node::setWestNode(Node *node) {
	m_westNode = node;
	adjacentNodes.push_back(node);
	//adjacentNodes[3] = node;
}

std::vector<Node*> Node::getAdjacentNodes() const {
	return adjacentNodes;
}

Node* Node::getNorthNode() const {
	return m_northNode;
}
Node* Node::getEastNode() const {
	return m_eastNode;
}
Node* Node::getSouthNode() const {
	return m_southNode;
}
Node* Node::getWestNode() const {
	return m_westNode;
}

std::string &Node::getIdentifier() {
	return m_identifier;
}