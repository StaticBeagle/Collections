#pragma once

template <class T>
class List
{
  public:
    List()
        : m_capacity{10},
          m_count{0}
    {
        m_data = new T[10];
    }

    List(size_t size)
        : m_capacity{size},
          m_count{size}
    {
        m_data = new T[size];
    }

    List(size_t size, T fill)
        : m_capacity{size},
          m_count{size}
    {
        m_data = new T[size];
        for (size_t i = 0; i < size; ++i)
        {
            m_data[i] = fill;
        }
    }

    List(const List<T> &other)
        : m_data{new T[other.m_count]},
          m_capacity{other.m_capacity},
          m_count{other.m_count}
    {
        std::copy(other.m_data, other.m_data + other.m_count, this->m_data);
    }

    List(List<T> &&other)
        : m_data{nullptr},
          m_capacity{0},
          m_count{0}
    {
        *this = std::move(other);
    }

    ~List()
    {
        delete[] m_data;
        m_data = nullptr;
    }

    void clear()
    {
        delete[] m_data;
        m_data = new T[10];
        m_count = 0;
        m_capacity = 10;
    }

    void add(const T &e)
    {
        if (m_count++ == m_capacity)
        {
            m_capacity += m_capacity >> 1;
            this->grow_container(m_capacity);
        }
        m_data[m_count - 1] = e;
    }

    size_t size()
    {
        return m_count;
    }

    size_t capacity()
    {
        return m_capacity;
    }

    // void resize(size_t size)
    // {
    //     // check that size > 0
    //     if(size > m_capacity)
    //     {
    //         m_capacity = size;
    //         this->grow_container(size);
    //         return;
    //     }
    //     m_count = size;
    // }

    // copy assignment operator
    List<T> &operator=(const List<T> &other)
    {
        if (this != &other)
        {
            delete[] this->m_data;

            this->m_count = other.m_count;
            this->m_capacity = other.m_capacity;
            this->m_data = new T[this->m_count];
            std::copy(other.m_data, other.m_data + other.m_count, this->m_data);
        }
        return *this;
    }

    // Move assignment operator.
    List<T> &operator=(List<T> &&other)
    {
        if (this != &other)
        {
            delete[] this->m_data;

            this->m_data = other.m_data;
            this->m_count = other.m_count;
            this->m_capacity = other.m_capacity;

            other.m_data = nullptr;
            other.m_count = 0;
            other.m_capacity = 0;
        }
        return *this;
    }

    T &operator[](size_t index)
    {
        return m_data[index];
    }

    const T &operator[](size_t index) const
    {
        return m_data[index];
    }

    void print()
    {
        for (size_t i = 0; i < m_count; ++i)
        {
            std::cout << m_data[i] << std::endl;
        }
    }

  private:
    T *m_data;
    size_t m_capacity;
    size_t m_count;

    void grow_container(size_t size)
    {
        T *data = new T[size];
        std::copy(this->m_data, this->m_data + this->m_count, data);
        delete[] m_data;
        m_data = data;
        data = nullptr;
    }
};