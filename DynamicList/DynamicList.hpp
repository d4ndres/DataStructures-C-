//Entrada y salida de datos
#include <iostream>

//Tiene una funcion move que permite trasladar los datos de un objeto. Sin necesidad de crear copias inecearias
// #include <utility>


using namespace std;

template <typename T>
class DynamicList
{
    private:
        int size;
        int *shape;
        T *list;
        T **listOfList;
        
    public:
        ~DynamicList();

        DynamicList(T *list, int size);
        
        DynamicList(T **listOfList, int rows, int cols);
        //Trow error if index off
        void setItem( int index, T item);

        void setItem( int row, int col, T item);

        void destroid();

        int* getShape();

        int getRows();
        
        int getCols();

        int getSize();

        void print();

};

template <typename T>
DynamicList<T>::DynamicList(T *list, int size) {
    this->listOfList = nullptr;
    this->list = list;
    this->size = size;
}

template <typename T>
DynamicList<T>::DynamicList(T **listOfList, int rows, int cols) {
    this->list = nullptr;
    this->listOfList = listOfList;
    this->shape = new int[2] {rows, cols};
    this->size = this->shape[0]*this->shape[1];
}

template <typename T>
DynamicList<T>::~DynamicList()
{
    this->destroid();
}

template <typename T>
void DynamicList<T>::setItem( int index, T item) {
    this->list[index] = item;
}

template <typename T>
void DynamicList<T>::setItem( int row, int col, T item)
{
    this->listOfList[row][col] = item;
}

template <typename T>
void DynamicList<T>::destroid()
{
    if ( list != nullptr)
    {
        delete[] list;
    }
    
    if ( listOfList != nullptr )
    {
        for ( int row = 0; row < this->getRows(); row++ )
        {
            delete[] listOfList[row];
        }
        delete[] listOfList;
    }
}


template <typename T>
int* DynamicList<T>::getShape()
{
    return this->shape;
}

template <typename T>
int DynamicList<T>::getRows(){
    return this->shape[0];
}

template <typename T>
int DynamicList<T>::getCols(){
    return this->shape[1];
}

template <typename T>
int DynamicList<T>::getSize(){
    return this->size;
}


template <typename T>
void DynamicList<T>::print(){
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
