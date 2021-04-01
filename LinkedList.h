#include "Car.h"

// Linked List and Node classes
class Node{
	public:
		Node();
		Node(Car newCar);
		friend class LinkedList;
	private:
		Car car;
		Node* prev;
		Node* next;
};

class LinkedList {


public:
	LinkedList();
	void insertFront(Node* new_node);
	Node* removeFront();
	Node* removeEnd();
	int size() const;
	bool isEmpty() const;
	int getValue();
	
private:
	Node* head;
	Node* tail;
};

		
		
