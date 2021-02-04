#pragma once
//
//  linked_List.hpp
//  linked_list
//
//  Created by Manjesh Prasad on 1/3/21.
//


#include <stdio.h>
#include <iostream>
using namespace std;

template<typename T>

class linked_list
{
public:

    linked_list();                  // class constructor

    ~linked_list();                 // class deconstructor

    void append(int);               // adds node to the end of the list

    bool contain(int);              // see if the element is in the list

    void print();                   // prints out the entire list

    void insertion(int num);        // inserts it in the middle of the list

    T getTotalNode();               // returns the total amount of nodes (observer)

    void deleteNode(int);           // delete node

private:

    struct node                 // the structure of the entire list
    {
        int number;
        node* next;
    };

    node* head;

    T total;
};


//**************** Definitions of the class functions ************************** //
template <typename T>
linked_list<T>::linked_list()
{
    total = 0;
    head = nullptr;
}


template <typename T>
linked_list<T>::~linked_list()
{
    node* nodeptr;
    node* iterateNext;                          // for saving the next node

    nodeptr = head;                                 // nodeptr = head

    while (nodeptr)                         // while nodeptr != nullptr
    {
        iterateNext = nodeptr->next;            // save the next node
        delete nodeptr;                         // delete the current node

        nodeptr = iterateNext;
    }
}


template <typename T>
void linked_list<T>::append(int num)        // adds new element to the middle of the list
{                                           // time complexity O(1)
    node* newNode = new node;               // initialize the newNode to a 'new' node
    node* nodeptr;                          // To iterate the entire list

    newNode->next = nullptr;                // initialie the newNode with the number and nullptr
    newNode->number = num;

    if (!head)                               // if there is no head, then head == newNode
    {
        head = newNode;
        total = 1;
        return;
    }
    nodeptr = head;

    while (nodeptr->next)                    // while nodeptr != nullptr
    {
        nodeptr = nodeptr->next;
    }
    nodeptr->next = newNode;
    total++;
    return;
}


template<typename T>
bool linked_list<T>::contain(int num)       // see if the list contains the integer
{                                           // Time complexity O(n)
    node* nodeptr;
    if (!head)                               // if no head, return false
    {
        return false;
    }

    nodeptr = head;

    while (nodeptr)                          // while nodeptr != nullptr
    {
        if (nodeptr->number == num)        // if the nodeptr->number == the number we need to see, return true
        {
            return true;
        }

        nodeptr = nodeptr->next;
    }
    return false;                         // if it goes through the entire list without hitting true, it dne
}

template<typename T>
void linked_list<T>::print()                // print the entire list
{
    node* nodeptr;

    if (!head)                               // if there is no head, return
    {
        getTotalNode();
        cout << "\nLIST IS EMPTY " << endl << endl;
        return;
    }

    nodeptr = head;

    getTotalNode();
    cout << endl;
    while (nodeptr != nullptr)               // while nodeptr != nullptr
    {
        cout << nodeptr->number;      // print out the number in the list
        nodeptr = nodeptr->next;
        cout << " -> ";
    }

    cout << "NULL " << endl;

    return;
}

template <typename T>
T linked_list<T>::getTotalNode()
{
    cout << "\n There are: " << total << " nodes in the list " << endl;
    return total;
}


template <typename T>
void linked_list<T>::deleteNode(int num)
{                                           // time complexity O(n)
    node* nodeptr;
    node* previousNode = nullptr;                     // Saving the previous nodes as we iterate
    if (!head)                               // if there is no head, retrun
    {
        return;
    }


    if (contain(num))                        // Check to see if the number exist within the list first
    {
        nodeptr = head;                     // Initialize the nodeptr to iterate through the list
        if (nodeptr->number == num)          // If head is equal to the number - delete the head and update
        {                                   // the list
            nodeptr = nodeptr->next;
            delete head;
            head = nodeptr;
            total--;
            return;
        }

        while (nodeptr->next && nodeptr->number != num)  // while the node != nullptr and not equal the number
        {
            previousNode = nodeptr;
            nodeptr = nodeptr->next;
        }

        if (nodeptr->number == num)                      // if the node is in the middle of the list/tail
        {
            previousNode->next = nodeptr->next;
            delete nodeptr;
            total -= 1;
            return;
        }
    }
    return;
}


template <typename T>
void linked_list<T>::insertion(int num)             // time complexity O(1) sometimes O(n)
{
    node* newNode = new node;                       // for the newNode
    node* nodeptr;                                  // iterate through the entire list
    node* previousNode = nullptr;

    newNode->number = num;
    newNode->next = nullptr;

    if (!head)                                      // if there is no head, set the newNode as the head
    {
        head = newNode;
        return;
    }

    nodeptr = head;

    while (nodeptr->next != nullptr && nodeptr->number < num)
    {
        previousNode = nodeptr;                     // save the  current node onto the previous
        nodeptr = nodeptr->next;                    // go to the next node
    }

    if (previousNode == nullptr)                     // if nothing is saved onto the previous node
    {                                               // then the value is placed onto the head
        newNode->next = nodeptr;
        head = newNode;
        total++;
        return;

    }
    else if (num < nodeptr->number)                  // if the number has to go between the list
    {
        previousNode->next = newNode;              // previousnode->next has to be the new Node
        previousNode = previousNode->next;         // update previousnode with the newNode included
        previousNode->next = nodeptr;               // add the rest of the list
        total++;
        return;
    }
    else
        return;

}