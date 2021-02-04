#include <iostream>
#include "linkedList.h"
#include <fstream>
using namespace std;

int main()
{
    linked_list<int> l;
    ifstream inFile;

    inFile.open("Linkedlist.txt");

    if (!inFile)
    {
        cout << "\nCannot open file " << endl;
        return 0;
    }

    int num;
    string directions;
    while (!inFile.eof() || directions != "QUIT")
    {

        inFile >> directions;
   
        if (directions == "print")
        {
            l.print();
        }
        else if (directions == "append")
        {
            inFile >> num;
            l.append(num);
        }
        else if (directions == "insert")
        {
            inFile >> num;

            l.insertion(num);
        }
        else if (directions == "delete")
        {
            inFile >> num;
            l.deleteNode(num);
        }
        else
        {
            inFile.close();
            break;
        }

   
    }
    cout << endl << endl;



}