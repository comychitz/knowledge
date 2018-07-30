#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include <iostream>

class Node 
{
  public:
    Node(const int &val) : next(NULL), value(val) {  }

    ~Node() {  }

    Node *next;
    int value;
};

class LinkedList
{
  public:
    LinkedList() : first(NULL), last(NULL) {  }

    virtual ~LinkedList() {  }

    /**
     * insert a new node into the list
     */
    virtual void append(Node *n) = 0;

    /**
     * remove a node from the list
     */
    virtual void remove(Node *n) = 0;

    /**
     * reverse the linked-list 
     */
    virtual void reverse() = 0;

    /**
     * print list 
     */
    void print() const
    {
      Node *cur = first;
      while(cur != NULL)
      {
        std::cout << cur->value << " ";
        cur = cur->next;
      }
      if(first == NULL)
      {
        std::cout << "(empty)";
      }
      std::cout << std::endl;
    }

    Node *first, *last;
};

#endif
