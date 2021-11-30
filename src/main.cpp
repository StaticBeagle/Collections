#include <iostream>
#include "linkedlist.h"
#include "list.h"
#include "stack.h"
#include "queue.h"
#include "dictionary.h"
#include "ordered_dictionary.h"

void test_linked_list()
{
    LinkedList<int> linkedList;
    std::cout << "Initial linked list" << std::endl;
    linkedList.push_back(4);
    linkedList.push_back(3);
    linkedList.print();

    std::cout << "Inserted 5 to pos = 1 to the linked list" << std::endl;
    linkedList.insert(1, 5);
    linkedList.print();

    std::cout << "Inserted 6 to pos = 0 to the linked list" << std::endl;
    linkedList.insert(0, 6);
    linkedList.print();

    std::cout << "pushed 8 to front of linked list" << std::endl;
    linkedList.push_front(8);
    linkedList.print();

    std::cout << "pushed 10 to back of linked list" << std::endl;
    linkedList.push_back(10);
    linkedList.print();

    std::cout << "popped back of the linked list" << std::endl;
    linkedList.pop_back();
    linkedList.print();

    std::cout << "popped front of the linked list" << std::endl;
    linkedList.pop_front();
    linkedList.print();

    std::cout << "Cleared the linked list" << std::endl;
    linkedList.clear();
    std::cout << "Current linked list" << std::endl;
    linkedList.print();
    std::cout << std::endl;
}

void test_stack()
{
    Stack<int> stack;
    std::cout << "Pushed 4 into the stack" << std::endl;
    stack.push(4);
    std::cout << "Pushed 3 into the stack" << std::endl;
    stack.push(3);
    std::cout << "Initial stack" << std::endl;
    stack.print();
    std::cout << "Popped the top of the stack" << std::endl;
    stack.pop();
    std::cout << "Current stack" << std::endl;
    stack.print();
    std::cout << "Popped the top of the stack" << std::endl;
    stack.pop();
    std::cout << "Current stack" << std::endl;
    stack.print();
    std::cout << std::endl;

    std::cout << "Pushed 4 into the stack" << std::endl;
    stack.push(4);
    std::cout << "Pushed 3 into the stack" << std::endl;
    stack.push(3);
    std::cout << "Cleared the stack" << std::endl;
    stack.clear();
    std::cout << "Current stack" << std::endl;
    stack.print();
    std::cout << std::endl;
}

void test_queue()
{
    Queue<int> queue;
    std::cout << "Pushed 4 into the queue" << std::endl;
    queue.push(4);
    std::cout << "Pushed 3 into the queue" << std::endl;
    queue.push(3);
    std::cout << "Initial queue" << std::endl;
    queue.print();
    std::cout << "Popped the top of the queue" << std::endl;
    queue.pop();
    std::cout << "Current queue" << std::endl;
    queue.print();
    std::cout << "Popped the top of the queue" << std::endl;
    queue.pop();
    std::cout << "Current queue" << std::endl;
    queue.print();
    std::cout << std::endl;

    std::cout << "Pushed 4 into the queue" << std::endl;
    queue.push(4);
    std::cout << "Pushed 3 into the queue" << std::endl;
    queue.push(3);
    std::cout << "Cleared the queue" << std::endl;
    queue.clear();
    std::cout << "Current queue" << std::endl;
    queue.print();
    std::cout << std::endl;
}

void test_list()
{
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
    std::cout << std::endl;
}

void test_dictionary()
{
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
    std::cout << std::endl;
}

void test_ordered_dictionary()
{
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
    std::cout << std::endl;
}

int main()
{
    test_linked_list();
    test_stack();
    test_queue();
    test_list();
    test_dictionary();
    test_ordered_dictionary();
}