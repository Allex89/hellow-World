#pragma once
#include <string>
using namespace std;
class Node {
private:

	string name;
	string type;
public:
	Node(string, string);
	Node();
	~Node();
	string getName();
	string getType();
	Node* Next;
};

class List {
private:
	Node* root;
public:
	Node* getRoot();
	void AddNode(Node* node);
	Node* FindByName(string name);
	List();
	~List();
};