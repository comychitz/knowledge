#include "BinaryHeap.cpp"

int main( int argc, const char *argv[] )
{
  BinaryHeap maxHeap, minHeap(false);
  std::vector<int> vals;
  vals.push_back(10);
  vals.push_back(2);
  vals.push_back(3);
  vals.push_back(8);
  vals.push_back(5);
  vals.push_back(6);
  vals.push_back(12);
  makeBinaryHeap(vals, maxHeap);
  maxHeap.print();
  std::cout << "max: " << maxHeap.top() << std::endl;

  makeBinaryHeap(vals, minHeap);
  minHeap.print();
  std::cout << "min: " << minHeap.top() << std::endl;

  return 0;
}
