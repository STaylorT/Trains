//Doubly Linked List 
#include "LinkedList.h"
#include <iostream>
using namespace std;

Node::Node(){
	prev = NULL;
	next = NULL;
}
// constructor for Node
Node::Node(Car newCar){
	car = newCar;
	prev = NULL;
	next = NULL;
}
//constructor for LinkedList
LinkedList::LinkedList(){
	head = new Node();
	tail = new Node();
	
	//make DLL empty
	head->next = tail;
	tail->prev = head;
	}
	
// method for inserting node at from of DLL
void LinkedList::insertFront(Node* new_node){
	//check if DLL is empty
	if (head == NULL && tail ==NULL){
		head->next = new_node;
		new_node->prev = head;
		new_node->next = tail;
		tail->prev = new_node;
		new_node->car.setPosition(1);
	}
	//if DLL not empty, add new node, and resolve pointers correctly
	else{
		new_node->next = head->next;
		head->next = new_node;
		new_node->next->prev = new_node;
		new_node->prev = head;
		Node* current = head->next;
		while (current != tail){
			current->car.setPosition(current->car.getPosition()+1);
			current = current->next;
			}
		
		new_node->car.setPosition(1);

		/**while(current != NULL){
			current
			current = current->next;
		}*/
	}
}
// remove front node (not head)
Node* LinkedList::removeFront(){
	if (size() ==0){
		cout << "List is Empty" << endl;
		return NULL;
		}
		else{ //resolving pointers for head and new front node
			Node* removing = head->next;
			head->next = removing->next;
			removing->next->prev = head;
			Node* current = head->next;
			while (current != tail){
			current->car.setPosition(current->car.getPosition()-1);
			current = current->next;
			}
			return removing; //return the node that we removed
		}
	}
	// remove node from back (not tail):/
Node* LinkedList::removeEnd(){
	if(size() == 0){
		cout << "list Empty" << endl;
		return NULL;
	}
	else{ //resolving pointers for tail and new back node
		Node* removing = tail->prev;
		tail->prev = removing->prev;
		removing->prev->next = tail;
		return removing;
		}
	}
	// return size of DLL, not including head and tail
	int LinkedList::size() const{
		int count = 0 ;
		Node* current = head;
		while (current != NULL){
			current = current->next;
			count++;
			}
		return count-2; //head and tail are metadata, not nodes here..\_--_/
	}
	
	// function to see if DLL is empty
	bool LinkedList::isEmpty() const{
		return size() ==0;
	}
	
	//Return Sum of values of cars in train, aka value of the entire train
	int LinkedList::getValue(){
		
		int value = 0;
		// define iterating node
		Node* currentNode = head->next;
		// make sure not to iterate through tail
		while (currentNode != NULL){
		//accessing value of each car via car function getValue()
		value += currentNode->car.getValue();
			currentNode =currentNode->next;
		}
		
		return value;
	}
		
