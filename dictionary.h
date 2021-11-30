#pragma once

#include "list.h"

template <class K, class V>
class Dictionary
{
  private:
    template <class TKey, class TValue>
    struct Entry
    {
      public:
        size_t hash;
        K key;
        V value;
        Entry<K, V> *next = nullptr;
    };

  public:
    Dictionary()
        : m_buckets{16, nullptr},
          m_capacity{16},
          m_count{0},
          m_load_factor{0.75}
    {
    }

    ~Dictionary()
    {
        for (size_t i = 0; i < m_buckets.size(); ++i)
        {
            Entry<K, V> *e = m_buckets[i];
            while (e != nullptr)
            {
                Entry<K, V> *tmp = e;
                e = e->next;
                delete tmp;
            }
        }
    }

    void add(const K &key, const V &value)
    {
        size_t hash = std::hash<K>{}(key);
        size_t i = index_for(hash, m_capacity);
        for (Entry<K, V> *e = m_buckets[i]; e != nullptr; e = e->next)
        {
            if (e->hash == hash && e->key == key)
            {
                // V& oldValue = e->value;
                e->value = value;
                return;
                // return oldValue;
            }
        }
        ++m_count;
        this->add_entry(hash, key, value, i);
    }

    V *get(K key) const
    {
        size_t hash = std::hash<K>{}(key);
        size_t i = index_for(hash, m_capacity);
        for (Entry<K, V> *e = m_buckets[i]; e != nullptr; e = e->next)
        {
            if (e->hash == hash && e->key == key)
            {
                return &e->value;
            }
        }
        return nullptr;
    }

    size_t size() const
    {
        return m_count;
    }

    void print()
    {
        for (size_t i = 0; i < m_buckets.size(); ++i)
        {
            Entry<K, V> *e = m_buckets[i];
            while (e != nullptr)
            {
                std::cout << "{ " << e->key << ": " << e->value << " }" << std::endl;
                e = e->next;
            }
        }
    }

  private:
    List<Entry<K, V> *> m_buckets;
    size_t m_capacity;
    size_t m_count;
    double m_load_factor;

    size_t index_for(size_t hash, size_t size)
    {
        return hash & (size - 1);
    }

    void grow_container(size_t size)
    {
        List<Entry<K, V> *> newBuckets{size, nullptr};
        for (size_t i = 0; i < m_buckets.size(); ++i)
        {
            Entry<K, V> *e = m_buckets[i];
            while (e != nullptr)
            {
                size_t hash = std::hash<K>{}(e->key);
                size_t index = index_for(hash, size);
                e->hash = hash;
                if (newBuckets[index] == nullptr)
                {
                    newBuckets[index] = e;
                }
                else
                {
                    newBuckets[index]->next = e;
                }
                e = e->next;
                newBuckets[index]->next = nullptr;
            }
        }
        m_buckets = std::move(newBuckets);
    }

    void add_entry(size_t hash, const K &key, const V &value, size_t i)
    {
        if (m_count > static_cast<size_t>(m_capacity * m_load_factor))
        {
            m_capacity *= 2;
            this->grow_container(m_capacity);
        }
        Entry<K, V> *e = new Entry<K, V>{hash, key, value};
        if (m_buckets[i] == nullptr)
        {
            m_buckets[i] = e;
        }
        else
        {
            m_buckets[i]->next = e;
        }
    }
};