//
//  main.cpp
//  linked_list
//
//  Created by Manjesh Prasad on 1/3/21.
//

#include <iostream>
#include "linked_List.hpp"

int main()
{
    linked_list<int> l;
    
    l.print();
    
    l.append(2);
    l.append(4);
    l.append(6);
    l.append(8);
    l.append(10);
    
    l.print();
    
    cout << endl << endl;
    l.insertion(1);
    l.insertion(7);
    l.insertion(5);
    l.print();
    
    cout << endl << endl;
    l.deleteNode(1);
    l.deleteNode(4);
    l.print();
    
    cout << endl << endl;
    
    
    
}
