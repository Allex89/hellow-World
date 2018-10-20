#include<iostream>
#include<string>
#include "AccessTable.h"

using namespace std;

AccessTable::AccessTable(){
    for(int i=0; i < tableSize; i++){
        accessTable[i] = new item;
        accessTable[i] ->name="empty";
        accessTable[i] ->inf.type = "empty";
        accessTable[i] ->inf.num = "empty";
        accessTable[i] ->next = NULL;
    }
}
void AccessTable::AddItem(string name, string type, string num){
    int index = hashFunction(name);
    if(accessTable[index]->name == "empty"){
        accessTable[index]->name = name;
        accessTable[index]->inf.type = type;
        accessTable[index]->inf.num = num;
    }
    else{
        item* ptr = accessTable[index];
        item* n = new item;
        n->name = name;
        n->inf.type = type;
        n->inf.num = num;
        n->next = NULL;
        while(ptr->next !=NULL)
            ptr = ptr->next;
        ptr->next = n;
    }
}
    int AccessTable::NumberOfItemsIndex(int index){
        int count = 0;
        if(accessTable[index]->name == "empty" )
            return count;
        else{
            count++;
            item* ptr = accessTable[index];
			while(ptr->next!=NULL){
                count++;
                ptr = ptr->next;
            }
        }
        return count;
    }
    void AccessTable::PrintTable(){
        int number;
        for(int i=0; i<tableSize; i++){
            number = NumberOfItemsIndex(i);
            cout << "--------------\n";
            cout << "index = " << i << endl;
            cout << accessTable[i]->name <<endl;
            cout << "Info Field: " << endl;
            cout << "Type: " << accessTable[i]->inf.type <<endl;
            cout << "Number: " << accessTable[i]->inf.num <<endl;
            cout << "Number Of items = " <<number << endl;
            cout << "--------------\n";
        }
    }
    void AccessTable::printItemsInIndex(int index){
        item* ptr = accessTable[index];
        if(ptr->name == "empty" )
            cout << "index '" << index << "' is empty"<<endl;
        else{
            cout << "index " << index << " Contains The Following Items: \n";
            while(ptr != NULL){
                cout << "-------------------\n";
                cout << "Name: " <<ptr->name << endl;
                cout << "Info Field: "<< endl;
                cout << "Type: " << ptr->inf.type <<endl;
                cout << "Number: " << ptr->inf.num <<endl;
                ptr = ptr->next;
            }
        }
    }


int AccessTable::hashFunction(string key){
    int hash = 0;
    int index;
    
    for(int i=0; i<key.length(); i++)
        hash += (int)key[i];
    index = hash % tableSize;
    return index;
}
void AccessTable::FindIdentifier(string name){
    int index = hashFunction(name);
    bool foundName = false;
    info info;
    item* ptr = accessTable[index];
    while(ptr !=NULL){
        if(ptr->name == name){
            foundName = true;
            info.type = ptr->inf.type;
            info.num = ptr->inf.num;
        }
        ptr = ptr->next;
    }
    if(foundName == true){
        cout << "Info Field for '" << name << "'"<< endl;
        cout << "Type: " << info.type << endl;
        cout << "Number: " << info.num << endl;
    }
    else
        cout << name << " not found in the Access Table\n";  
}
void AccessTable::RemoveItem(string name){
    int index = hashFunction(name);
    item* delptr;
    item* p1;
    item* p2;
    
    if(accessTable[index]->name == "empty")
        cout << name << " not found in the Access Table\n";
    else if(accessTable[index]->name == name && accessTable[index]->next == NULL ){
        accessTable[index]->name = "empty";
        accessTable[index]->inf.type = "empty";
        accessTable[index]->inf.num = "empty";
        cout << name << " was removed from the Access Table\n";
    }
    else if (accessTable[index]->name == name){
        delptr = accessTable[index];
        accessTable[index] = accessTable[index]->next;
        delete delptr;
        cout << name << " was removed from the Access Table\n";
    }
    else {
			p1 = accessTable[index]->next;
			p2 = accessTable[index];
        while(p1 !=NULL && p1->name !=name){
            p2 = p1;
            p1 = p1->next;
        }
    
		if(p1 == NULL)
			cout << name << " not found in the Access Table\n";
		else{
			delptr = p1;
			p1 = p1->next;
			p2->next = p1;
			delete delptr;
			cout << name << " was removed from the Access Table\n";
		}
    }
}