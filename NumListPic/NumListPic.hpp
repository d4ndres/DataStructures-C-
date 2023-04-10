#include <iostream>
#include <exception>

using namespace std;

template <typename T>
class NumListPic
{
    private:
        int size;
        int *shape;
        T *list;
        T **listOfList;
        
    public:
   
        NumListPic( int size = 0, T *list = nullptr);
        NumListPic( int rows, int cols, T **listOfList = nullptr);
        
        ~NumListPic();
        void destroid();

        void setItem( int index, T item);
        void setItem( int row, int col, T item);

        int* getShape();

        int getRows();
        
        int getCols();

        int getSize();

        void print();
};

template <typename T>
NumListPic<T>::NumListPic( int size, T *list) 
{
    if ( size < 0) {
        throw invalid_argument("The size must be greater than zero");
    
    } else if ( size == 0 ) {
        this->listOfList = nullptr;
        this->list = nullptr;
    
    } else {
        this->listOfList = nullptr;
        this->size = size;
        this->list = new T[size];

        if ( list != nullptr ){
            for ( int i = 0; i < size; i++ ) {
                this->list[i] = list[i];
            }
        
        }
    }
}

template <typename T>
NumListPic<T>::NumListPic( int rows, int cols, T **listOfList )
{
    if ( rows <= 0 || cols <= 0 ) {
        throw invalid_argument("The rows and cols must be greater than zero");
    } else {
        this->listOfList = new T*[rows];
        this->list = nullptr;
        this->shape = new int[2] {rows, cols};

        for ( int i = 0; i < rows; i++ ) {
            this->listOfList[i] = new T[cols];
        }

        if ( listOfList != nullptr) {
            for ( int iRow = 0; iRow < rows; iRow++ ) {
                for ( int iCol = 0; iCol < rows; iCol++ ) {
                    this->listOfList[iRow][iCol] = listOfList[iRow][iCol];
                }                
            }
        }

    }
}

template <typename T>
NumListPic<T>::~NumListPic()
{
    this->destroid();
}

template <typename T>
void NumListPic<T>::setItem( int index, T item) {
    this->list[index] = item;
}

template <typename T>
void NumListPic<T>::setItem( int row, int col, T item)
{
    this->listOfList[row][col] = item;
}

template <typename T>
void NumListPic<T>::destroid()
{
    if ( list != nullptr)
    {
        delete[] &list;
        delete[] list;
    }
    
    if ( listOfList != nullptr )
    {
        for ( int row = 0; row < this->getRows(); row++ )
        {
            delete[] &listOfList[row];
            delete[] listOfList[row];
        }
        delete[] &listOfList;
        delete[] listOfList;
    }
}

template <typename T>
int* NumListPic<T>::getShape()
{
    return this->shape;
}

template <typename T>
int NumListPic<T>::getRows(){
    return this->shape[0];
}

template <typename T>
int NumListPic<T>::getCols(){
    return this->shape[1];
}

template <typename T>
int NumListPic<T>::getSize(){
    return this->size;
}

template <typename T>
void NumListPic<T>::print()
{
        if ( this->listOfList == nullptr )
        {
            cout<<"[";
            for (int i = 0; i < this->getSize(); i++){
                cout<<this->list[i]<<( i == this->getSize() - 1? "":",");
            }
            cout<<"]"<<endl;
        }
        else 
        {
            cout<<"[";
            for ( int row = 0; row < this->getRows(); row++ ){
                cout<<"[";
                for ( int col = 0; col < this->getCols(); col++){
                    cout << this->listOfList[row][col] << ( col == this->shape[1] - 1? "":",\t");
                }
                cout<<"]" << ( row == this->shape[0] - 1? "":",\n");
            }
            cout<<"]"<<endl;
        }
}
