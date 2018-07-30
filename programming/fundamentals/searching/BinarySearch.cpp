#include <iostream>
#include <vector>


/**
 * sample: find: 2
 * [0] [1] [2] [3] [4]
 *  1   2   3   5   7
 */
static int binarySearch_(int value, int start, int end, 
                         const std::vector<int> &input)
{
  if(start > end)
  {
    return -1;
  }
  else if(start == end)
  {
    return input[start] == value ? start : -1;
  }

  int middle = start + (end-start)/2;
  if(value < input[middle])
  {
    return binarySearch_(value, start, (middle)-1, input);
  }
  else if(value > input[middle])
  {
    return binarySearch_(value, (middle)+1, end, input);
  }
  return middle;
}

/**
 * search for the given value in the input array
 * @return index of value, -1 if not found
 */
int binarySearch(const int value, const std::vector<int> &input)
{
  return binarySearch_(value, 0, input.size()-1, input);
}

int main( int argc, const char *argv[] )
{
  std::vector<int> values;

  values.push_back(1);
  values.push_back(3);
  values.push_back(5);
  values.push_back(8);
  values.push_back(8);
  values.push_back(10);
  values.push_back(12);
  values.push_back(20);

  for(unsigned i = 0; i < values.size(); ++i)
  {
    std::cout << values[i] << " ";
  }
  std::cout << std::endl;

  int value = 5;
  std::cout << "Found value: " << value << " at index: " 
            << binarySearch(value, values) << std::endl;

  value = 6;
  std::cout << "Found value: " << value << " at index: " 
            << binarySearch(value, values) << std::endl;

  value = 8;
  std::cout << "Found value: " << value << " at index: " 
            << binarySearch(value, values) << std::endl;

  value = 12;
  std::cout << "Found value: " << value << " at index: " 
            << binarySearch(value, values) << std::endl;

  return 0;
}
