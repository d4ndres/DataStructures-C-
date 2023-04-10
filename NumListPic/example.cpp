#include <iostream>
#include "NumListPic.hpp"
using namespace std;

int main() {

    int list[] = {1,2,3,4};
    int size = sizeof(list)/sizeof(list[0]);
    NumListPic<int> *numList = new NumListPic<int>(size, list );
    numList->print();

    int rows = 3;
    int cols = 4;
    int **LD2 = new int*[rows] {    new int[cols] {1, 2, 3, 4},
                                    new int[cols] {5, 6, 7, 8},
                                    new int[cols] {9, 10, 11, 12} };

    NumListPic<int> *numList2D = new NumListPic<int>(rows, cols, LD2 );
    numList2D->print();

}
