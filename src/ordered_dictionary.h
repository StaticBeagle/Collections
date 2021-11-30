#pragma once

#include "list.h"

template <class K, class V>
class OrderedDictionary
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
        Entry<K, V> *before = nullptr;
        Entry<K, V> *after = nullptr;
    };

public:
    OrderedDictionary()
        : m_buckets{16},
          m_capacity{16},
          m_count{0},
          m_load_factor{0.75},
          m_before{nullptr},
          m_begin{nullptr}
    {
        for (size_t i = 0; i < m_buckets.size(); ++i)
        {
            m_buckets.add(nullptr);
        }
    }

    ~OrderedDictionary()
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

    bool is_empty() const
    {
        return m_count == 0;
    }

    void print()
    {
        Entry<K, V> *e = m_begin;
        while (e != nullptr)
        {
            std::cout << "{ " << e->key << ": " << e->value << " }";
            Entry<K, V> *current = e;
            while (current->next != nullptr)
            {
                current = current->next;
                std::cout << ", { " << current->key << ": " << current->value << " }";
            }
            std::cout << std::endl;
            e = e->after;
        }
    }

private:
    List<Entry<K, V> *> m_buckets;
    size_t m_capacity;
    size_t m_count;
    double m_load_factor;

    Entry<K, V> *m_before;
    Entry<K, V> *m_begin;

    size_t index_for(size_t hash, size_t size)
    {
        return hash & (size - 1);
    }

    void grow_container(size_t capacity)
    {
        List<Entry<K, V> *> newBuckets{capacity};
        for (size_t i = 0; i < capacity; ++i)
        {
            newBuckets.add(nullptr);
        }
        for (size_t i = 0; i < m_buckets.size(); ++i)
        {
            Entry<K, V> *e = m_buckets[i];
            if (e == nullptr)
            {
                continue;
            }
            size_t hash = std::hash<K>{}(e->key);
            size_t index = index_for(hash, capacity);
            e->hash = hash;
            newBuckets[index] = e;
        }
        m_buckets = std::move(newBuckets);
    }

    void add_entry(size_t hash, const K &key, const V &value, size_t i)
    {
        Entry<K, V> *e = new Entry<K, V>{hash, key, value};
        if (this->is_empty())
        {
            m_begin = e;
        }
        else
        {
            m_before->after = e;
        }
        this->ensure_capacity();
        this->add_to_bucket(i, e);
        e->before = m_before;
        m_before = e;
        ++m_count;
    }

    void add_to_bucket(size_t index, Entry<K, V> *e)
    {
        if (m_buckets[index] == nullptr)
        {
            m_buckets[index] = e;
        }
        else
        {
            Entry<K, V> *current = m_buckets[index];
            while (current->next != nullptr)
            {
                current = current->next;
            }
            current->next = e;
        }
    }

    void ensure_capacity()
    {
        if (m_count > static_cast<size_t>(m_capacity * m_load_factor))
        {
            m_capacity *= 2;
            this->grow_container(m_capacity);
        }
    }
};