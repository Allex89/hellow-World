#pragma once
#include<iostream>
#include<string>
using namespace std;

#ifndef ACCESSTABLE_H
#define ACCESSTABLE_H

class AccessTable{

private:
    static const int tableSize = 4;
    
    struct info{
        string type;
        string num;
    };
    
    struct item{
        string name;
        struct info inf;
        item* next;
    };
    
    item* accessTable[tableSize];
    
public: 
    AccessTable();
    int hashFunction(string key);
    void AddItem(string name, string type, string num);
    int NumberOfItemsIndex(int index);
    void PrintTable();
    void printItemsInIndex(int index);
    void FindIdentifier(string name);
    void RemoveItem(string name);
    
}



;
#endif /* ACCESSTABLE_H */