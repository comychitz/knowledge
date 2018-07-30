#include "BinaryHeap.h"
#include <iostream>

//
// [0]  [1] [2] [3] [4] [5]
// [10] [5] [8] [2] [4] [6]
//

static bool parent(int index, const std::vector<int> &vals, int &parent)
{
  if(index == 0)
  {
    return false;
  }
  parent = index/2;
  if(index%2 == 0)
  {
    parent--; 
  }
  return true;
}

void BinaryHeap::siftUp(int index)
{
  bool met = false;
  int parentIndex;
  if(!parent(index, vals_, parentIndex))
  {
    return;
  }
  if(max_)
  { 
    met = vals_[index] < vals_[parentIndex];
  }
  else 
  {
    met = vals_[index] > vals_[parentIndex];
  }

  if(!met)
  {
    int tmp;
    tmp = vals_[index];
    vals_[index] = vals_[parentIndex];
    vals_[parentIndex] = tmp;
    siftUp(parentIndex);
  }
}

BinaryHeap::BinaryHeap(bool max) : max_(max)
{
}

BinaryHeap::~BinaryHeap()
{
}

int BinaryHeap::top()
{
  return vals_[0];
}

void BinaryHeap::push(int val)
{
  vals_.push_back(val);
  siftUp(vals_.size()-1);  
}

void BinaryHeap::pop()
{
  //
  // TODO
  //
}

void BinaryHeap::print()
{ //
  // todo update me to print in breadth-first order
  //
  for(std::vector<int>::const_iterator v = vals_.begin(); v != vals_.end(); ++v)
  {
    std::cout << *v << " ";
  }
  std::cout << std::endl;
}
