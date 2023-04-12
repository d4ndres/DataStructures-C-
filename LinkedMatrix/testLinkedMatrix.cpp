#include <iostream>
#include "LinkedMatrix.hpp"
using namespace std;

int main()
{

    //Test 1: shape
    LinkedMatrix<int> matrix;
    matrix.shape()->print();

    //Test 2: write and read
    int x = 0;
    for ( int i = 0; i <= 8; i ++)
    {
        for( int j = 0; j <= 12; j++ )
        {

            matrix.write( i, j, i*j );
        }
    }

    //test 3: remplace
    matrix.write( 1,1,55);

    matrix.print();
    
    matrix.shape()->print();

    // test 4: get copy of row and col, remplace and confirm.
    LinkedList<int> *xRow = matrix.getRow(3);
    cout << xRow->length() << endl;
    xRow->write(1,715);
    xRow->print();
    matrix.print();

    LinkedList<int> *xCol = matrix.getColumn(7);
    xCol->write(0,715);
    cout << endl;
    xCol->print();
    cout << endl;
    matrix.print();

    // test 5: fill a new matrix adn confirm no clonficts
    LinkedMatrix<float> zeros;
    zeros.initFill(3,5, 0);
    zeros.print(' '); 

    // test 6: get max element in matrix
    cout << "Element max in matrix is " << matrix.maxElement() << endl;

    return 0;
}