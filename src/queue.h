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
        m_top = new QueueNode<T>();
    }

    ~Queue()
    {
        this->clear();
        m_top->next = nullptr;
        delete m_top;
    }

    void push(const T& obj)
    {
        QueueNode<T>* node = m_top;
        while(node->next != nullptr)
        {
            node = node->next;
        }
        node->next = new QueueNode<T>();
        node->next->data = obj;
        ++m_count;
    }

    void pop()
    {
        if(this->is_empty()) {
            return;
        }
        QueueNode<T>* node = m_top;
        m_top = m_top->next;
        delete node;
        --m_count;
    }

    void clear()
    {
        while(m_top->next != nullptr)
        {
            QueueNode<T>* tmp = m_top;
            m_top = m_top->next;
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
        QueueNode<T>* node = m_top->next;
        while(node != nullptr)
        {
            std::cout << node->data << std::endl;
            node = node->next;
        }
    }
private:
    QueueNode<T>* m_top;
    size_t m_count;
};