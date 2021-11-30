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

    std::cout << "Dictionary " << std::endl;
    Dictionary<int, int> dict;
    dict.add(1, 1);
    dict.add(2, 3);
    dict.add(3, 6);
    dict.add(4, 5);
    dict.add(5, 8);
    dict.add(6, 9);
    dict.add(7, 0);
    dict.add(8, 7);
    dict.add(9, 4);
    dict.add(10, 14);
    dict.add(11, 11);
    dict.add(12, 10);
    dict.add(13, 12);
    dict.print();

    std::cout << "Ordered Dictionary " << std::endl;
    OrderedDictionary<int, int> ordDict;
    ordDict.add(1, 1);
    ordDict.add(1, 2);
    ordDict.add(1, 3);
    ordDict.add(2, 3);
    ordDict.add(3, 6);
    ordDict.add(4, 5);
    ordDict.add(5, 8);
    ordDict.add(6, 9);
    ordDict.add(7, 0);
    ordDict.add(8, 7);
    ordDict.add(9, 4);
    ordDict.add(10, 14);
    ordDict.add(11, 11);
    ordDict.add(12, 10);
    ordDict.add(13, 12);
    ordDict.print();
}