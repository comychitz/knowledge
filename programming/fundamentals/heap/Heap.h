#ifndef _HEAP_H_
#define _HEAP_H_

class Heap
{
  public:
    virtual ~Heap() { }

    /**
     * add a new value to the heap
     */
    virtual void push(int val) = 0;

    /**
     * get a copy of the top of the heap
     */
    virtual int top() = 0;

    /**
     * remove the node at the top of the heap
     */
    virtual void pop() = 0;

    /**
     * print out the heap, breadth-firsth
     */
    virtual void print() = 0;
};

#endif
