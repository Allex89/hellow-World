#include<iostream>
#include<string>
#include "SymbolTable.h"
#include"List.h"

using namespace std;


SymbolTable::SymbolTable(int size){
	tableSize = size;
	symbolTable = new List*[size];
	for (int i = 0; i < size; i++) {
		symbolTable[i] = NULL;
	}
}
SymbolTable::~SymbolTable() {
	for(int i =0;i < tableSize;i++) {
		delete symbolTable[i];
	}
	delete[] symbolTable;
}
Node* SymbolTable::addItem(string name, string type) {
	int index = hashFunction(name);
	if (symbolTable[index] == NULL) {
		symbolTable[index] = new List();
	}
	Node* node = new Node(name, type);
	symbolTable[index]->AddNode(node);
	return node;
}

Node* SymbolTable::AddIfNotExist(string name , string type) {
	// find using name
	Node* node = Find(name);
	// if not exist
	if (node == NULL) {
		return addItem(name, type);
	} else {
		return node;
	}
}

Node* SymbolTable::Find(string name) {
	int index = hashFunction(name);

	if(symbolTable[index] == NULL) {
		return NULL;
	}

	return symbolTable[index]->FindByName(name);
}

int SymbolTable::hashFunction(string key){
	int hash = 0;
	int index;

	for(int i=0; i<key.length(); i++)
		hash += (int)key[i];
	index = hash % tableSize;
	return index;
}
bool SymbolTable::Exists(string name){
	int index = hashFunction(name);
	bool foundName = false;
	List* list = symbolTable[index];
	if (list == NULL) return false;
	Node* node = list->FindByName(name);
	return node != NULL;
}

