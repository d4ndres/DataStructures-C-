#pragma once
#include "ListNode.hpp"
#include <stdexcept>
#include <iostream>
using namespace std;

//This is a class inspired by Python lists

template <typename T>
class LinkedList
{
    private:
        ListNode<T> *m_head;
        ListNode<T> *m_current;//Aunque sea el nodo actual. Siempre apuntara al ultimo nodo.
        LinkedList *m_nextList;
        int m_size;

    public:
        LinkedList();

        LinkedList( const LinkedList &other ) = delete;

        LinkedList operator = ( const LinkedList &other ) = delete;

        ~LinkedList();

        T at( int index) const;

        void append(T newElement );

        void insert( int index, T newElement);

        void write( int index, T newElement );

        void remove( T element );

        T pop( int index = -1 );

        int count( T element ) const;

        int length() const;

        void print( char _endl = '\t') const;

        void setNextList( LinkedList *nextList );

        LinkedList<T> *nextList() const;

};

template <typename T>
LinkedList<T>::LinkedList()
{
    //placeholder de donde inicia nuestra cabecera de la lista
    this->m_head = new ListNode<T>(0);
    this->m_size = 0;
    m_current = m_head;

    this->m_nextList = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    if( m_head != nullptr )
    {
        delete m_head;
        m_head = nullptr;
    }
    if( m_nextList != nullptr )
    {
        delete m_nextList;
        m_nextList = nullptr;
    }
}

//LinkedList.at( index )
//Return list element by position.
//a.at( -1 ) return last element of list
template <typename T>
T LinkedList<T>::at( int index) const
{
    if ( index >= m_size || index < -1 )
    {
        throw std::runtime_error("index out of range");
    }
    else if ( index == -1)
    {
        return m_current->value();
    }

    int i = 0;
    ListNode<T> *node = m_head->nextNode();
    while( node != nullptr && i < index)
    {
        node = node->nextNode();
        ++i;
    }
    if ( node != nullptr )
    {
        return node->value();
    }
    throw std::runtime_error("Contact me if this error occurs");
    // return -1;

}

//LinkedList.append( x )
//Add an item to the end of the list.
template <typename T>
void LinkedList<T>::append(T newElement )
{
    ListNode<T> *newNode = new ListNode<T>(newElement);
    m_current->setNextNode(newNode);
    m_current = newNode;
    ++m_size;
}

//LinkedList.insert( index, x )
//Insert an item at a given position.
//The first argument is the index of the element before which to insert, so a.insert(0, x) inserts at the front of the list.
//a.insert(len(a), x) or a.insert(len(a) + n, x) or a.insert( -1, x) is equivalent to a.append(x).
template <typename T>
void LinkedList<T>::insert( int index, T newElement)
{
    if( index < -1 )
    {
        throw std::runtime_error("index out of range");
    } 
    else if( index == -1 )
    {
        index = m_size;
    }

    ListNode<T> *newNode = new ListNode<T>(newElement);
    int i = 0;
    ListNode<T> *node = m_head->nextNode();
    ListNode<T> *prev = m_head;
    
    while( node != nullptr && i < index && i < m_size)
    {
        ++i;
        prev = node;
        node = node->nextNode();
    }

    if( prev != nullptr )
    {
        prev->setNextNode( newNode );

        if( node != nullptr )
        {
            newNode->setNextNode( node );
        }
        else 
        {
            m_current = newNode;
        }
        ++m_size;
    }
}

template <typename T>
void LinkedList<T>::write( int index, T newElement)
{
    this->insert( index, newElement );
    if ( index + 1 < m_size )
    {
        this->pop( index + 1);
    }
}

//LinkedList.remove( x )
//Remove the first item from the list whose value is equal to x.
template <typename T>
void LinkedList<T>::remove( T element )
{
    ListNode<T> *node = m_head->nextNode();
    ListNode<T> *prev = m_head;
    while (node != nullptr && node->value() != element)
    {
        prev = node;//Guardamos el nodo previo al encontrado.
        node = node->nextNode();//Si existe aca se guardara el elemento pra una posterior eliminacion.
    }

    if( node != nullptr)
    {
        prev->setNextNode(node->nextNode());
        if( prev->nextNode() == nullptr )
        {
            m_current = prev;
        }

        //Es necesario indicar que su siguiente nodo es nulo. de lo contrario al eliminarlo comienza una reaccion en cadena eliminando todo.
        node->setNextNode(nullptr);
        delete node;

        --m_size;
    }
}

//LinkedList.pop()
//Remove the item at the given position in the list, and return it. 
//If no index is specified, a.pop() or a.pop(-1) removes and returns the last item in the list.
template <typename T>
T LinkedList<T>::pop( int index)
{

    if( index >= m_size || index < -1 )
    {
        throw std::runtime_error("index out of range");
        // return -1;
    } 
    else if ( index == -1 ) 
    {
        index = m_size - 1;
    } 

    int i = 0;
    ListNode<T> *node = m_head->nextNode();
    ListNode<T> *prev = m_head;
    while( node != nullptr && i < index )
    {
        ++i;
        prev = node;
        node = node->nextNode();
    }
    if ( node != nullptr )
    {
        T item = node->value();

        //Aca se borra el nodo de nuestra lista
        prev->setNextNode( node->nextNode() );
        if( prev->nextNode() == nullptr )
        {
            m_current = prev;
        }

        //Tambien cabe destacar que las suiguientes dos lineas son solo para limpiar memoria
        node->setNextNode( nullptr );
        delete node;
        --m_size;

        return item;
    }
    else
    {
        throw std::runtime_error("Contact me if this error occurs");
        // return -1;
    }
}



//LinkedList.count( x )
//Return the number of times x appears in the list.
template <typename T>
int LinkedList<T>::count( T element ) const
{
    ListNode<T> *node = m_head->nextNode();
    int counter = 0;

    while( node != nullptr )
    {
       if( node->value() == element )
       {
            ++counter;
       }
       node = node->nextNode();
    }
    return counter;
}

//LinkedList.length()
//Return the length list
template <typename T>
int LinkedList<T>::length() const
{
    return m_size;
}

//LinkedList.print()
//Print the list
template <typename T>
void LinkedList<T>::print( char _endl) const 
{
    for( int i = 0; i < m_size; i++)
    {
        std::cout << this->at(i) << _endl;
    }
    std::cout << "\n";
}

template <typename T>
void LinkedList<T>::setNextList( LinkedList *nextList )
{
    m_nextList = nextList;
}

template <typename T>
LinkedList<T> *LinkedList<T>::nextList() const
{
    return m_nextList;
}