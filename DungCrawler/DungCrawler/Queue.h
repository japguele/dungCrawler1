#include "Node.h"

class Queue {
private:
	Node *front;
	Node *rear;
public:
	Queue();
	~Queue();
	bool isEmpty();
	void enqueue(int);
	int dequeue();
	void display();
};