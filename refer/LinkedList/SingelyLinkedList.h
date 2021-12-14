template <typename T>
class SingelyLinkedList
{
    class Node;

public:
    SingelyLinkedList<T>() noexcept
    {
        // caution: static members can't be
        // initialized by initializer list
        m_spRoot = nullptr;
    }

    // Forward declaration must be done
    // in the same access scope
    class Iterator;

    // Root of SingelyLinkedList wrapped in Iterator type
    Iterator begin()
    {
        return Iterator(m_spRoot);
    }

    // End of SingelyLInkedList wrapped in Iterator type
    Iterator end()
    {
        return Iterator(nullptr);
    }

    // Adds data to the end of list
    void push_back(T data);

    void Traverse();

    // Iterator class can be used to
    // sequentially access nodes of linked list
    class Iterator
    {
    public:
        Iterator() noexcept : m_pCurrentNode(m_spRoot) {}

        Iterator(const Node *pNode) noexcept : m_pCurrentNode(pNode) {}

        Iterator &operator=(Node *pNode)
        {
            this->m_pCurrentNode = pNode;
            return *this;
        }

        // Prefix ++ overload
        Iterator &operator++()
        {
            if (m_pCurrentNode)
                m_pCurrentNode = m_pCurrentNode->pNext;
            return *this;
        }

        // Postfix ++ overload
        Iterator operator++(int)
        {
            Iterator iterator = *this;
            ++*this;
            return iterator;
        }

        bool operator!=(const Iterator &iterator)
        {
            return m_pCurrentNode != iterator.m_pCurrentNode;
        }

        int operator*()
        {
            return m_pCurrentNode->data;
        }

    private:
        const Node *m_pCurrentNode;
    };

private:
    class Node
    {
        T data;
        Node *pNext;

        // SingelyLinkedList class methods need
        // to access Node information
        friend class SingelyLinkedList;
    };

    // Create a new Node
    Node *GetNode(T data)
    {
        Node *pNewNode = new Node;
        pNewNode->data = data;
        pNewNode->pNext = nullptr;

        return pNewNode;
    }

    // Return by reference so that it can be used in
    // left hand side of the assignment expression
    Node *&GetRootNode()
    {
        return m_spRoot;
    }

    static Node *m_spRoot;
};

template <typename T>
/*static*/ typename SingelyLinkedList<T>::Node *SingelyLinkedList<T>::m_spRoot = nullptr;

template <typename T>
void SingelyLinkedList<T>::push_back(T data)
{
    Node *pTemp = GetNode(data);
    if (!GetRootNode())
    {
        GetRootNode() = pTemp;
    }
    else
    {
        Node *pCrawler = GetRootNode();
        while (pCrawler->pNext)
        {
            pCrawler = pCrawler->pNext;
        }

        pCrawler->pNext = pTemp;
    }
}

template <typename T>
void SingelyLinkedList<T>::Traverse()
{
    Node *pCrawler = GetRootNode();

    while (pCrawler)
    {
        cout << pCrawler->data << " ";
        pCrawler = pCrawler->pNext;
    }

    cout << endl;
}
