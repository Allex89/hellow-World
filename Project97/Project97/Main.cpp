#include "SymbolTable.h"
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string name = "";
	int a;
	SymbolTable* access = new SymbolTable();
	Node* node;
	Node* node2;
	Node* node3;
	node = access->AddIfNotExist("hasan","f1");
	node2 = access->AddIfNotExist("nasah", "f2");
	node3 = access->AddIfNotExist("Ali", "f3");
	node3 = access->AddIfNotExist("Akbar", "f4");
	node3 = access->AddIfNotExist("Alireza", "f5");
	node3 = access->AddIfNotExist("rager", "f6");
	node3 = access->AddIfNotExist("mohammad", "f7");
	node3 = access->AddIfNotExist("davood", "f8");
	node3 = access->AddIfNotExist("dalir", "f9");
	
	
		access->PrintTable();
		while (true) {
		cout << "enter index to expand: ";
		cin >> a;
		access->PrintItemInIndex(a);
	}
   
    
    
    return 0;
}
