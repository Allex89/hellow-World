#pragma once
#include<iostream>
#include<string>
#include"List.h"
using namespace std;

#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

class SymbolTable{

private:
    int tableSize;
    List** symbolTable;
    int hashFunction(string key);
	Node* addItem(string name, string type);
public:
    SymbolTable(int size = 5);
	~SymbolTable();
    
	Node* AddIfNotExist(string name, string type);
	Node* Find(string name);
	bool Exists(string name);
	int NumberOfItemInIndex(int index);
	void PrintTable();
	void PrintItemInIndex(int index);
};
#endif /* SYMBOLTABLE_H */