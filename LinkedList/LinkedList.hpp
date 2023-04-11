#pragma once
#include "ListNode.hpp"

class LinkedList
{
    private:
        ListNode *m_head;
        ListNode *m_current;//Aunque sea el nodo actual. Siempre apuntara al ultimo nodo.
        unsigned m_size;

    public:
        LinkedList();

        LinkedList( const LinkedList &other ) = delete;

        LinkedList operator = ( const LinkedList &other ) = delete;

        ~LinkedList();

        int at( int index) const;

        void add(int newElement );

        void remove( int element );

        void removeAt( int index);

        bool constains( int element ) const;

        unsigned size() const;

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

int LinkedList::at( int index) const
{
    if ( index >= m_size )
    {
        return -1; // throw error
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

void LinkedList::add(int newElement )
{
    ListNode *newNode = new ListNode(newElement);
    m_current->setNextNode(newNode);
    m_current = newNode;
    ++m_size;
}

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
        //Es necesario indicar que su siguiente nodo es nulo. de lo contrario al eliminarlo comienza una reaccion en cadena eliminando todo.
        node->setNextNode(nullptr);
        delete node;

        --m_size;
    }
}

void LinkedList::removeAt( int index)
{
    if( index <= m_size)
    {
        return;
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
        //Aca se borra el nodo de nuestra lista
        prev->setNextNode( node->nextNode() );

        //Tambien cabe destacar que las suiguientes dos lineas son solo para limpiar memoria
        node->setNextNode( nullptr );
        delete node;
        --m_size;
    }
}

bool LinkedList::constains( int element ) const
{
    ListNode *node = m_head->nextNode();
    while( node != nullptr )
    {
       if( node->value() == element )
       {
        return true;
       }
       node = node->nextNode();
    }
    return false;
}

unsigned LinkedList::size() const
{
    return m_size;
}