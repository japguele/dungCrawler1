#include "Queue.h"
#include <iostream>

void Queue::display(){
	Node *p = new Node;
	p = front;
	if (front == NULL){
		std::cout << "\nNothing to Display\n";
	}
	else{
		while (p != NULL){
			std::cout << std::endl << p->getIdentifier;
			//p = p->next;
		}
	}
}

Queue::Queue() {
	front = NULL;
	rear = NULL;
}

Queue::~Queue() {
	delete front;
}

void Queue::enqueue(int data) {
	Node *temp = new Node("temp");
	temp->getIdentifier = data;
	//temp->next = NULL;
	/*if (front == NULL){
		front = temp;
	}
	else{
		rear->next = temp;
	}*/
	rear = temp;
}

int Queue::dequeue() {
	Node *temp = new Node();
	int value;
	if (front == NULL){
		std::cout << "\nQueue is Empty\n";
	}
	else{
		temp = front;
		value = temp->getIdentifier;
		//front = front->next;
		delete temp;
	}
	return value;
}