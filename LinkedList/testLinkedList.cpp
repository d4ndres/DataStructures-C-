#include <iostream>
#include "LinkedList.hpp"

using namespace std;

int main()
{
    LinkedList list;

    //test 1
    cout << list.length() << endl;

    //test 2, constains number
    if( list.count(23) )
    {
        cout << "List contains 23" << endl;
    }
    else 
    {
        cout << "List does not contains 23" << endl;
    }

    //test 3, append element
    list.append(5);
    list.append(10);
    list.append(7);

    //test 4, element at list
    list.print();

    //test 5, remove last element
    list.pop();
    list.print();

    //test 6, remove element in index
    for( int i = 0; i < 20; i += 2)
    {
        list.append(i);
    }

    list.print();

    list.pop(1);
    list.print();

    //test 7, remove element
    list.remove(10);
    list.print();

    //test 8, remove last element with element and append new elemnt
    list.remove(18);
    list.append(22);
    list.append(44);
    list.print();

    return 0;
}