#include "Node.h"
#include "stdafx.h"

Node::Node(Node &northNode, Node &eastNode, Node &southNode, Node &westNode) {
	m_northNode = &northNode;
	m_eastNode = &eastNode;
	m_southNode = &southNode;
	m_westNode = &westNode;
}

Node::Node() {
	//empty
}

void Node::setNorthNode(Node *node) {
	m_northNode = node;
}
void Node::setEastNode(Node *node) {
	m_eastNode = node;
}
void Node::setSouthNode(Node *node) {
	m_southNode = node;
}
void Node::setWestNode(Node *node) {
	m_westNode = node;
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