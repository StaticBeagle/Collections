#pragma once

template<class T>
class QueueNode
{
public:
    QueueNode* next = nullptr;
    T data;
};

template<class T>
class Queue
{
public:
    Queue() : 
        m_count { 0 }
    {
        m_base = new QueueNode<T>();
        m_base->next = nullptr;
    }

    ~Queue()
    {
        this->clear();
        m_base->next = nullptr;
        delete m_base;
    }

    void push(const T& obj)
    {
        QueueNode<T>* node = m_base;
        m_base = new QueueNode<T>();
        m_base->data = obj;
        m_base->next = node;
        ++m_count;
    }

    void pop()
    {
        if(this->is_empty()) {
            return;
        }
        QueueNode<T>* node = m_base;
        m_base = m_base->next;
        delete node;
        --m_count;
    }

    void clear()
    {
        while(m_base->next != nullptr)
        {
            QueueNode<T>* tmp = m_base;
            m_base = m_base->next;
            delete tmp;
        }
        m_count = 0;
    }

    bool is_empty()
    {
        return m_count == 0;
    }

    size_t size()
    {
        return m_count;
    }

    void print() 
    {
        QueueNode<T>* node = m_base;
        while(node->next != nullptr)
        {
            std::cout << node->data << std::endl;
            node = node->next;
        }
    }
private:
    QueueNode<T>* m_base;
    size_t m_count;
};