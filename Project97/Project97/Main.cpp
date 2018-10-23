#include "SymbolTable.h"
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string name = "";
	SymbolTable* access = new SymbolTable();
	Node* node;
	node = access->AddIfNotExist("hasan","string");
	cout<< node->getName();
	system("pause");
   
    
    
    return 0;
}
