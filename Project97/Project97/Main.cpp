#include "AccessTable.h"
#include<iostream>
#include<string>
using namespace std;

int main()
{
	string name = "";
    AccessTable access;
   
    access.AddItem("begin","int","23");
    access.AddItem("start","obj","44");
    access.AddItem("A","float","56");
    access.AddItem("B","real","78");
    access.AddItem("C","t2","66");
    access.AddItem("D","t1","75");
    access.AddItem("E","z1","85");
    access.AddItem("F","z2","95");
    access.AddItem("G","a1","105");
    access.AddItem("H","a2","110");
    access.AddItem("I","k1","810");
    access.AddItem("J","k2","1000");
    access.printItemsInIndex(2);
	access.PrintTable();
    
    while(name != "exit"){
        cout << "Remove:"; 
        cin >> name; 
        if(name != "exit")
            access.RemoveItem(name);
    }
     
    
    access.printItemsInIndex(2);
	

    
    
    return 0;
}
