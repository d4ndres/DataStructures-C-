#include "ListNode.hpp"
#include <iostream>
using namespace std;

int main() 
{
    ListNode<float> n1(5);
    cout << n1.value() << endl;

    ListNode<char> n2('s');
    cout << n2.value() << endl;

    ListNode<string> n3("HelloWord");

    if ( n3.value() == "HelloWord" )
    {
        cout << n3.value() << endl;
    } 
    else
    {
        cout << "You should never see this" << endl;
    }

    return 0;
}