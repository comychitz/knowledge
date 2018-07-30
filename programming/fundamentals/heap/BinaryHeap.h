#ifndef _BINARY_HEAP_H_
#define _BINARY_HEAP_H_

#include "Heap.h"
#include <vector>

class BinaryHeap : public Heap
{
  public:
    BinaryHeap(bool max = true);

    virtual ~BinaryHeap();

    void push(int val);

    int top();

    void pop();

    void print();

  private:
    void siftUp(int index);

    void siftDown(int index);
    
    std::vector<int> vals_;
    bool max_;
};

void makeBinaryHeap(const std::vector<int> &vals, BinaryHeap &heap)
{
  for(std::vector<int>::const_iterator v = vals.begin(); v != vals.end(); ++v)
  {
    heap.push(*v);
  }
}

#endif
