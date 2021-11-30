#pragma once

template <class T>
class LinkedList
{
  private:
    template <class U>
    struct LinkedListNode
    {
      public:
        LinkedListNode *next = nullptr;
        LinkedListNode *prev = nullptr;
        T data;
    };

  public:
    LinkedList()
        : m_head{new LinkedListNode<T>()},
          m_tail{new LinkedListNode<T>()},
          m_count{0}
    {

        m_head->next = m_tail;
        m_head->prev = nullptr;

        m_tail->next = nullptr;
        m_tail->prev = m_head;
    }

    ~LinkedList()
    {
        this->clear();
        delete m_head;
        delete m_tail;
    }

    LinkedList(const LinkedList<T> &other)
        : LinkedList{}
    {
        this->copy_list(other);
    }

    LinkedList(LinkedList<T> &&other)
        : LinkedList{}
    {
        *this = std::move(other);
    }

    T *front()
    {
        if (this->is_empty())
        {
            return nullptr;
        }
        return &m_head->next->data;
    }

    T *back()
    {
        if (this->is_empty())
        {
            return nullptr;
        }
        return &m_tail->prev->data;
    }

    // copy assignment operator
    LinkedList<T> &operator=(const LinkedList<T> &other)
    {
        if (this != &other)
        {
            this->clear();
            this->copy_list(other);
        }
        return *this;
    }

    // Move assignment operator.
    LinkedList<T> &operator=(LinkedList<T> &&other)
    {
        if (this != &other)
        {
            this->clear();
            m_head = other.m_head;
            m_tail = other.m_tail;
            m_count = other.m_count;

            other.m_head = nullptr;
            other.m_tail = nullptr;
            other.m_count = 0;
        }
        return *this;
    }

    T *operator[](size_t index)
    {
        if (this->is_empty())
        {
            return nullptr;
        }
        LinkedListNode<T> *node = m_head->next;
        for (size_t i = 0; i < index; ++i)
        {
            node = node->next;
        }
        return &node->data;
    }

    void push_front(const T &obj)
    {
        LinkedListNode<T> *node = new LinkedListNode<T>();
        node->data = obj;
        node->prev = m_head;
        node->next = m_head->next;
        m_head->next->prev = node;
        m_head->next = node;
        ++m_count;
    }

    void push_back(const T &obj)
    {
        LinkedListNode<T> *node = new LinkedListNode<T>();
        node->data = obj;
        node->next = m_tail;
        node->prev = m_tail->prev;
        m_tail->prev->next = node;
        m_tail->prev = node;
        ++m_count;
    }

    void push_back(T &&obj)
    {
        LinkedListNode<T> *node = new LinkedListNode<T>();
        node->data = std::move(obj);
        node->next = m_tail;
        node->prev = m_tail->prev;
        m_tail->prev->next = node;
        m_tail->prev = node;
        ++m_count;
    }

    void pop_front()
    {
        if (this->is_empty())
        {
            return;
        }
        LinkedListNode<T> *node = m_head->next;
        m_head->next = node->next;
        node->next->prev = m_head;
        node->prev = nullptr;
        node->next = nullptr;
        delete node;
        --m_count;
    }

    void pop_back()
    {
        if (this->is_empty())
        {
            return;
        }
        this->remove_last();
    }

    void insert(size_t index, const T &obj)
    {
        if (index < 0 || index > m_count)
        {
            // error
        }
        LinkedListNode<T> *tmp = m_head->next;
        for (size_t i = 0; i < index; ++i)
        {
            tmp = tmp->next;
        }

        LinkedListNode<T> *node = new LinkedListNode<T>();
        node->data = obj;
        node->next = tmp;
        node->prev = tmp->prev;
        tmp->prev->next = node;
        tmp->prev = node;
        ++m_count;
    }

    void clear()
    {
        while (!this->is_empty())
        {
            this->remove_last();
        }
    }

    size_t size() const
    {
        return m_count;
    }

    bool is_empty() const
    {
        return m_count == 0;
    }

    void print()
    {
        LinkedListNode<T> *node = m_head->next;
        while (node != m_tail)
        {
            std::cout << node->data << std::endl;
            node = node->next;
        }
    }

  private:
    LinkedListNode<T> *m_head;
    LinkedListNode<T> *m_tail;
    size_t m_count;

    void remove_last()
    {
        LinkedListNode<T> *node = m_tail->prev;
        m_tail->prev = node->prev;
        node->prev->next = m_tail;
        node->prev = nullptr;
        node->next = nullptr;
        delete node;
        --m_count;
    }

    void copy_list(const LinkedList<T> &other)
    {
        LinkedListNode<T> *node{other.m_head->next};
        while (node != other.m_tail)
        {
            this->push_back(node->data);
            node = node->next;
        }
    }
};