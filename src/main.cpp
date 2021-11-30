#include <iostream>
#include "linkedlist.h"
#include "list.h"
#include "stack.h"
#include "dictionary.h"
#include "ordered_dictionary.h"

int main()
{
    LinkedList<int> linkedList;
    std::cout << "Initial list" << std::endl;
    linkedList.push_back(4);
    linkedList.push_back(3);
    linkedList.print();

    std::cout << "Inserted 5 to pos = 1" << std::endl;
    linkedList.insert(1, 5);
    linkedList.print();

    std::cout << "Inserted 6 to pos = 0" << std::endl;
    linkedList.insert(0, 6);
    linkedList.print();

    std::cout << "pushed 8 to front of list" << std::endl;
    linkedList.push_front(8);
    linkedList.print();

    std::cout << "popped back of the list" << std::endl;
    linkedList.pop_back();
    linkedList.print();

    std::cout << "popped front of the list" << std::endl;
    linkedList.pop_front();
    linkedList.print();

    std::cout << "Cleared the linkedList" << std::endl;
    linkedList.clear();
    linkedList.print();

    Stack<int> stack;
    std::cout << "Initial stack" << std::endl;
    stack.push(4);
    stack.push(3);
    stack.print();

    List<int> list;
    std::cout << "Initial list" << std::endl;
    for (int i = 0; i < 15; ++i)
    {
        list.add(i);
    }
    for (size_t i = 0; i < list.size(); ++i)
    {
        std::cout << list[i] << std::endl;
    }

    // Using double as key to force collisions
    std::cout << "Dictionary " << std::endl;
    Dictionary<double, int> dict;
    dict.add(1.5, 1);
    dict.add(2.6, 3);
    dict.add(3.7, 6);
    dict.add(4.8, 5);
    dict.add(5.9, 8);
    dict.add(6.1, 9);
    dict.add(7.2, 0);
    dict.add(8.3, 7);
    dict.add(9.4, 4);
    dict.add(10.5, 14);
    dict.add(11.6, 11);
    dict.add(12.7, 10);
    dict.add(13.8, 12);
    dict.print();

    // Using double as key to force collisions
    std::cout << "Ordered Dictionary " << std::endl;
    OrderedDictionary<double, int> ordDict;
    ordDict.add(1.5, 1);
    ordDict.add(2.6, 3);
    ordDict.add(3.7, 6);
    ordDict.add(4.8, 5);
    ordDict.add(5.9, 8);
    ordDict.add(6.1, 9);
    ordDict.add(7.2, 0);
    ordDict.add(8.3, 7);
    ordDict.add(9.4, 4);
    ordDict.add(10.5, 14);
    ordDict.add(11.6, 11);
    ordDict.add(12.7, 10);
    ordDict.add(13.8, 12);
    ordDict.print();
}