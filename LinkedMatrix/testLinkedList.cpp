#include <iostream>
#include "LinkedList.hpp"
using namespace std;


int main()
{
    LinkedList<int> list;

    for ( int i = 0; i < 10; i ++)
    {
        list.append(i*i);
    }
    list.print();
    list.write(2,137);
    list.print();

    list.write(55, 1);
    list.print();


    return 0;
}