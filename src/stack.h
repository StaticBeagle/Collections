#pragma once

template<class T>
class StackNode
{
public:
    StackNode* next = nullptr;
    T data;
};

template<class T>
class Stack
{
public:
    Stack() : 
        m_count { 0 }
    {
        m_base = new StackNode<T>();
        m_base->next = nullptr;
    }

    ~Stack()
    {
        this->clear();
        m_base->next = nullptr;
        delete m_base;
    }

    void push(const T& obj)
    {
        StackNode<T>* node = m_base;
        m_base = new StackNode<T>();
        m_base->data = obj;
        m_base->next = node;
        ++m_count;
    }

    void pop()
    {
        if(this->is_empty()) {
            return;
        }
        StackNode<T>* node = m_base;
        m_base = m_base->next;
        delete node;
        --m_count;
    }

    void clear()
    {
        while(m_base->next != nullptr)
        {
            StackNode<T>* tmp = m_base;
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
        StackNode<T>* node = m_base;
        while(node->next != nullptr)
        {
            std::cout << node->data << std::endl;
            node = node->next;
        }
    }
private:
    StackNode<T>* m_base;
    size_t m_count;
};