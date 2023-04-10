#include <iostream>
#include "DynamicList.hpp"
using namespace std;


int main() {

    int rows = 3;
    int cols = 4;
    int **LD2 = new int*[rows] {    new int[cols] {1, 2, 3, 4},
                                    new int[cols] {5, 6, 7, 8},
                                    new int[cols] {9, 10, 11, 12} };
    
    int *LD1 = new int[6] {1,2,3,4,5,6};

    DynamicList<int> *list = new DynamicList<int>( LD1, 6 );
    DynamicList<int> *list2d = new DynamicList<int>( LD2, rows, cols );
    
    cout << list->getSize() << endl;
    list->print();
    list->destroid();

    list2d->print();
    list2d->setItem( 1, 1, 55);
    list2d->print();
    list2d->destroid();

}