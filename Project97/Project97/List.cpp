#include "List.h"


Node::Node() {
	Next = NULL;
}

Node::Node(string _name, string _type) {
	name = _name;
	type = _type;
	Next = NULL;
}
Node::~Node() {
	delete Next;
}

string Node::getName(){
	return name;
}

string Node::getType() {
	return type;
}


List::List(){
	root = NULL;
}

List::~List(){
	delete root;
}

Node* List::getRoot() {
	return root;
}

void List::AddNode(Node* node) {
	if (root == NULL) {
		root = node;
		return;
	}
	Node* head = root;
	while(head != NULL) {
		if (head->Next == NULL) {
			head->Next = node;
			break;
		}
		head = head->Next;
	}
}

Node* List::FindByName(string name) {
	Node* head = root;
	while(head !=NULL){
		if(head->getName() == name){
			return head;
		}
		head = head->Next;
	}
	return NULL;
}