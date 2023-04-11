#pragma once

template <typename T> 
class ListNode
{
    private:
        T m_value;
        ListNode *m_nextNode;

    public:
        ListNode( T value );

        ListNode( const ListNode &other ) = delete;

        ListNode operator = ( const ListNode &other) = delete;

        ~ListNode();

        T value() const;

        ListNode *nextNode() const;

        void setNextNode( ListNode *nextNode );

};

template <typename T> 
ListNode<T>::ListNode( T value )
{
    this->m_value = value;
    this->m_nextNode = nullptr;

}

template <typename T> 
ListNode<T>::ListNode::~ListNode()
{
    if( m_nextNode != nullptr )
    {
        delete m_nextNode;
        m_nextNode = nullptr;
    }
}

template <typename T> 
T ListNode<T>::ListNode::value() const
{
    return m_value;
}

template <typename T> 
ListNode<T> *ListNode<T>::nextNode() const
{
    return m_nextNode;
}

template <typename T> 
void ListNode<T>::setNextNode( ListNode *nextNode )
{
    m_nextNode = nextNode;
}