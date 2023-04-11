#pragma once
#include "ListNode.hpp"
#include <stdexcept>
#include <iostream>

//This is a class inspired by Python lists
class LinkedList
{
    private:
        ListNode *m_head;
        ListNode *m_current;//Aunque sea el nodo actual. Siempre apuntara al ultimo nodo.
        int m_size;

    public:
        LinkedList();

        LinkedList( const LinkedList &other ) = delete;

        LinkedList operator = ( const LinkedList &other ) = delete;

        ~LinkedList();

        int at( int index) const;

        void append(int newElement );

        void insert( int index, int newElement);

        void remove( int element );

        int pop( int index = -1 );

        int count( int element ) const;

        int length() const;

        void print() const;

};


LinkedList::LinkedList()
{
    //placeholder de donde inicia nuestra cabecera de la lista
    this->m_head = new ListNode(0);
    this->m_size = 0;
    m_current = m_head;
}

LinkedList::~LinkedList()
{
    if( m_head != nullptr )
    {
        delete m_head;
        m_head = nullptr;
    }
}

//LinkedList.at( index )
//Return list element by position.
//a.at( -1 ) return last element of list
int LinkedList::at( int index) const
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
    ListNode *node = m_head->nextNode();
    while( node != nullptr && i < index)
    {
        node = node->nextNode();
        ++i;
    }
    if ( node != nullptr )
    {
        return node->value();
    }
    return -1;

}

//LinkedList.append( x )
//Add an item to the end of the list.
void LinkedList::append(int newElement )
{
    ListNode *newNode = new ListNode(newElement);
    m_current->setNextNode(newNode);
    m_current = newNode;
    ++m_size;
}

//LinkedList.insert( index, x )
//Insert an item at a given position.
//The first argument is the index of the element before which to insert, so a.insert(0, x) inserts at the front of the list.
//a.insert(len(a), x) or a.insert(len(a) + n, x) or a.insert( -1, x) is equivalent to a.append(x).
void LinkedList::insert( int index, int newElement)
{
    if( index < -1 )
    {
        throw std::runtime_error("index out of range");
    } 
    else if( index == -1 )
    {
        index = m_size;
    }

    ListNode *newNode = new ListNode(newElement);
    int i = 0;
    ListNode *node = m_head->nextNode();
    ListNode *prev = m_head;
    
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

//LinkedList.remove( x )
//Remove the first item from the list whose value is equal to x.
void LinkedList::remove( int element )
{
    ListNode *node = m_head->nextNode();
    ListNode *prev = m_head;
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
int LinkedList::pop( int index)
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
    ListNode *node = m_head->nextNode();
    ListNode *prev = m_head;
    while( node != nullptr && i < index )
    {
        ++i;
        prev = node;
        node = node->nextNode();
    }
    if ( node != nullptr )
    {
        int item = node->value();

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
int LinkedList::count( int element ) const
{
    ListNode *node = m_head->nextNode();
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
int LinkedList::length() const
{
    return m_size;
}

//LinkedList.print()
//Print the list
void LinkedList::print() const 
{
    for( int i = 0; i < m_size; i++)
    {
        std::cout << this->at(i) << " ";
    }
    std::cout << "\n";
}