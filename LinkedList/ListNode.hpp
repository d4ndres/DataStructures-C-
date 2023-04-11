#pragma once

class ListNode
{
    private:
        int m_value;
        ListNode *m_nextNode;

    public:
        ListNode( int value );

        ListNode( const ListNode &other ) = delete;

        ListNode operator = ( const ListNode &other) = delete;

        ~ListNode();

        int value() const;

        ListNode *nextNode() const;

        void setNextNode( ListNode *nextNode );

};

ListNode::ListNode( int value )
{
    this->m_value = value;
    this->m_nextNode = nullptr;

}

ListNode::~ListNode()
{
    if( m_nextNode != nullptr )
    {
        delete m_nextNode;
        m_nextNode = nullptr;
    }
}

int ListNode::value() const
{
    return m_value;
}

ListNode *ListNode::nextNode() const
{
    return m_nextNode;
}

void ListNode::setNextNode( ListNode *nextNode )
{
    m_nextNode = nextNode;
}