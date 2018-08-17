#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/**
 * maximum subarray problem
 *
 * approaches:
 * - divide and conquer
 * - kadane's algorithm (uses this here)
 */

int maxSubArray(vector<int> &a)
{
  int max = a.at(0), tmpMax = a.at(0);
  for(int i = 1; i < a.size(); i++)
  {
    tmpMax = ::max(a.at(i), tmpMax + a.at(i));
    max = ::max(max, tmpMax);
  }
  return max;
}

int main(int argc, const char *argv[])
{
  vector<int> arr;
  arr.push_back(-5);
  arr.push_back(6);
  arr.push_back(7);
  arr.push_back(1);
  arr.push_back(4);
  arr.push_back(-8);
  arr.push_back(16);

  cout << maxSubArray(arr) << endl;
  
  return 0;
}
