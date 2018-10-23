#pragma once
#include <string>
using namespace std;
class Node {
private:

	string name;
	string type;
public:
	Node* Next;
	std::string getName();
	Node(string, string);
	Node();
	~Node();
};

class List {
private:
	Node* root;
public:
	void AddNode(Node*);
	Node* FindByName(string name);
	List();
	~List();
};