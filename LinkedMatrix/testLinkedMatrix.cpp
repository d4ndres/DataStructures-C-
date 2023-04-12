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
    for ( int i = 0; i <= 10; i ++)
    {
        for( int j = 0; j <= 10; j++ )
        {

            matrix.write( i, j, i*j );
        }
    }

    //test 3: remplace
    matrix.write( 1,1,55);

    matrix.print();
    
    matrix.shape()->print();

    return 0;
}