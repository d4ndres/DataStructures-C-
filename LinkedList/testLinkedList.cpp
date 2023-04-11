#include <iostream>
#include "LinkedList.hpp"

using namespace std;

int main()
{
    LinkedList<float> list;

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
    list.append(10.56);
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
    list.append(22.44);
    list.append(44);
    list.print();

    //test 9, insert
    list.insert( 0, 74);
    list.print();

    list.insert( 8995, 333);
    list.print();

    list.append(74);
    list.print();

    list.insert( 1, 66);
    list.print();

    //test 10, no conflicts between instances,
    LinkedList<int> listInt;
    listInt.append(2);
    listInt.append(-3);
    listInt.append(-25);
    listInt.print();
    list.print();
    listInt.append(0);
    list.append(23.45);
    list.print();
    listInt.print();

    //test 11, linkedlist in linkedlist
    // LinkedList<LinkedList<int>> ints;
    


    //Test #, strigns list does not work
    // LinkedList<string> week;
    // week.append("Monday");
    // week.append("Thusday");
    // week.append("Wenesday");
    // week.append("Thurstday");
    // week.append("Fryday");
    // week.append("Saturday");
    // week.append("Sunday");
    // week.print();

    return 0;
}