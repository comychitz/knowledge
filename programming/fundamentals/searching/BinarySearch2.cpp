#include <vector>
#include <iostream>
#include <unistd.h>

using namespace std;

/**
 * return true if found the search element in arr
 */
bool binarySearch(vector<int> &arr, int start, int end, int &val) {
  if(start > end) {
    return false;
  }
  if(start == end) {
    return val == arr.at(start);
  }
  int middle = start+((end-start)/2);
  if(arr.at(middle) == val) {
    return true;
  } else if(arr.at(middle) < val) {
    return binarySearch(arr, middle+1, end, val);
  } 
  return binarySearch(arr, start, middle-1, val);
}

int main(int argc, const char *argv[])
{
  vector<int> arr = {1,2,3,4,5,6,7,8,9,10,12,15};
  for(int i = 0; i < 15; i++) {
    cout << "Is " << i << " in array? " 
      << (binarySearch(arr, 0, arr.size()-1, i) ? "YES" : "NO") << endl;
  }
  return 0;
}
