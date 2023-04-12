#pragma once
#include <stdexcept>
#include <iostream>
#include "LinkedList.hpp"

//it works. but works with a lot of memory and also does not clean the used memory.
//And 

template <typename T>
class LinkedMatrix
{
    private:
        LinkedList<T> *m_head;
        LinkedList<T> *m_current;
        int m_size;

        void append();

    public:

        LinkedMatrix();

        LinkedMatrix( const LinkedMatrix &other ) = delete;

        LinkedMatrix operator = ( const LinkedMatrix &other ) = delete;

        ~LinkedMatrix();

        T at( int row, int col ) const;

        T maxElement() const;

        void write( int row, int col, T newElemet );

        int length() const;

        void print(char _endl = '\t') const;

        LinkedList<int>* shape() const;

        LinkedList<T>* getColumn( int colIndex) const;

        LinkedList<T>* getRow( int rowIndex) const;

        void initFill( int rows, int cols, T element );

        
};

template<class T> 
T LinkedMatrix<T>::maxElement() const
{

    T max = 0;
    for ( int i = 0; i < this->shape()->at(0); i ++)
    {
        for( int j = 0; j < this->shape()->at(1); j++ )
        {
            T element = this->at( i, j);
            max = max < element ? element : max;
        }
    }
    return max;

}


template <typename T>
void LinkedMatrix<T>::initFill( int rows, int cols, T element )
{
    for ( int i = 0; i < rows; i ++)
    {
        for( int j = 0; j < cols; j++ )
        {
            this->write( i, j, element );
        }
    }
}

template <typename T>
LinkedMatrix<T>::LinkedMatrix()
{
    this->m_head = new LinkedList<T>();
    this->m_size = 0;
    m_current = m_head;

}

template <typename T>
LinkedMatrix<T>::~LinkedMatrix()
{
    if( m_head != nullptr )
    {
        delete m_head;
        m_head = nullptr;
    }
}

template <typename T>
LinkedList<T> *LinkedMatrix<T>::getRow( int rowIndex ) const
{

    LinkedList<T> *node = m_head->nextList();

    int i = 0;
    while( i < rowIndex )
    {
        ++i;
        node = node->nextList();
    }

    LinkedList<T> *row = new LinkedList<T>();

    //copy
    for ( int i = 0; i < node->length(); i++ )
    {
        row->append( node->at(i) );
    }

    //Reference selft
    // row = node;


    return row;
}

template <typename T>
LinkedList<T> *LinkedMatrix<T>::getColumn( int colIndex) const
{
    LinkedList<T> *col = new LinkedList<T>;

    LinkedList<T> *node = m_head->nextList();

    int i = 0;
    while( node != nullptr )
    {
        ++i;
        col->append( node->at(colIndex) );
        node = node->nextList();
    }

    return col;
}

template <typename T>
T LinkedMatrix<T>::at( int row, int col ) const
{
    LinkedList<T> *node = m_head->nextList();
    LinkedList<T> *prev = m_head;

    int i = 0;
    while( node != nullptr && i < row )
    {
        ++i;
        prev = node;
        node = node->nextList();
    }
    return node->at(col);
}

template <typename T>
void LinkedMatrix<T>::append()
{
    LinkedList<T> *newNode = new LinkedList<T>();
    m_current->setNextList(newNode);
    m_current = newNode;
    ++m_size;
}

template <typename T>
void LinkedMatrix<T>::write( int row, int col, T newElement )
{
    ListNode<T> *newNode = new ListNode<T>(newElement);
    LinkedList<T> *node = m_head->nextList();

    int i = 0;
    while( node != nullptr && i < row )
    {
        ++i;
        node = node->nextList();
    }

    if( node == nullptr )
    {
        this->append();
        node = m_current;
    }

    node->write( col, newElement );

}


template <typename T>
int LinkedMatrix<T>::length() const
{
    return m_size;
}

template <typename T>
LinkedList<int> *LinkedMatrix<T>::shape() const
{
    LinkedList<int> *shape = new LinkedList<int>();
    shape->append( this->length() ); 
    shape->append( m_current->length() );
    return shape;
}

template <typename T>
void LinkedMatrix<T>::print( char _endl ) const
{
    std::cout << "\n";
    for ( int i = 0; i < this->shape()->at(0); i ++)
    {
        for( int j = 0; j < this->shape()->at(1); j++ )
        {
            std::cout << this->at(i, j) << _endl;
        }
        std::cout << "\n";
    }
}