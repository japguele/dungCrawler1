

class Node
{
private:
	Node* m_northNode;
	Node* m_eastNode;
	Node* m_southNode;
	Node* m_westNode;

public :
	Node();
	Node(Node &northNode, Node &eastNode, Node &southNode, Node &westNode);
	Node* getNorthNode() const;
	Node* getEastNode() const;
	Node* getSouthNode() const;
	Node* getWestNode() const;

	void setNorthNode(Node *node);
	void setEastNode(Node *node);
	void setSouthNode(Node *node);
	void setWestNode(Node *node);
};