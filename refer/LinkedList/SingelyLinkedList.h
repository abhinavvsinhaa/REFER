#include <bits/stdc++.h>
using namespace std;

template <typename T>
class SingelyLinkedList
{
    class Node;

public:
    SingelyLinkedList<T>()
    {
        m_spRoot = nullptr;
    }

    class Iterator;
    Iterator begin()
    {
        return Iterator(m_spRoot);
    }
    Iterator end()
    {
        return Iterator(nullptr);
    }
    void push_back(T data);

    void Traverse();
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
        Iterator &operator++()
        {
            if (m_pCurrentNode)
                m_pCurrentNode = m_pCurrentNode->pNext;
            return *this;
        }
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
        friend class SingelyLinkedList;
    };

    Node *GetNode(T data)
    {
        Node *pNewNode = new Node;
        pNewNode->data = data;
        pNewNode->pNext = nullptr;

        return pNewNode;
    }

    Node *&GetRootNode()
    {
        return m_spRoot;
    }

    static Node *m_spRoot;
};

template <typename T>
typename SingelyLinkedList<T>::Node *SingelyLinkedList<T>::m_spRoot = nullptr;

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
