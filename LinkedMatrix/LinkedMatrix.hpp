#pragma once
#include <stdexcept>
#include <iostream>
#include "LinkedList.hpp"

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

        void write( int row, int col, T newElemet );

        int length() const;

        void print(char _endl = '\t') const;

        LinkedList<T>* shape() const;
};

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
LinkedList<T> *LinkedMatrix<T>::shape() const
{
    LinkedList<int> *shape = new LinkedList<int>();
    shape->append( this->length() ); 
    shape->append( m_current->length() );
    return shape;
}

template <typename T>
void LinkedMatrix<T>::print( char _endl ) const
{
    for ( int i = 0; i < this->shape()->at(0); i ++)
    {
        std::cout << "\n";
        for( int j = 0; j < this->shape()->at(1); j++ )
        {
            std::cout << this->at(i, j) << _endl;
        }
    }
}