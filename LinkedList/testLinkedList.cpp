#include <iostream>
#include "LinkedList.hpp"

using namespace std;

int main()
{
    LinkedList list;
    cout << list.size() << endl;
    if( list.constains(23) )
    {
        cout << "List contains 23" << endl;
    }
    else 
    {
        cout << "List does not contains 23" << endl;
    }
    list.add(5);
    list.add(10);
    list.add(7);

    
    for( int i = 0; i < list.size(); i++)
    {
        cout << list.at(i) << " ";
    }
    cout << endl;

    list.remove(120);

    for( int i = 0; i < list.size(); i++)
    {
        cout << list.at(i) << " ";
    }
    cout << endl;

    return 0;
}