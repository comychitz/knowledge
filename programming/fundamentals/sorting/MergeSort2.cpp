#include <iostream>
#include <vector>
#include <unistd.h>

using namespace std;

static vector<int> merge(vector<int> a, vector<int> b) {
  vector<int> res;
  int i = 0, j = 0;
  while(i < a.size() && j < b.size()) {
    if(a.at(i) <= b.at(j)) {
      res.push_back(a.at(i++));
    } else {
      res.push_back(b.at(j++));
    }
  }
  while(i < a.size()) {
    res.push_back(a.at(i++));
  }
  while(j < b.size()) {
    res.push_back(b.at(j++));
  }
  return res;
}

static void printArr(const vector<int> &arr) {
  for(auto &a : arr) {
    cout << a << " ";
  }
  cout << endl;
}

static vector<int> mergeSort(vector<int> arr) {
  if(arr.empty() || arr.size() == 1) {
    return arr;
  }
  if(arr.size() == 2) {
    if(arr.at(0) > arr.at(1)) {
      swap(arr.at(0), arr.at(1)); 
    }
    return arr;
  }
  vector<int> a, b, c, d;
  // NOTE: remember, insert does NOT include the *last* argument
  a.insert(a.end(), arr.begin(), arr.begin()+arr.size()/2);
  b.insert(b.end(), arr.begin()+arr.size()/2, arr.end());
  c = mergeSort(a);
  d = mergeSort(b);
  return merge(c, d);
}

int main(int argc, const char *argv[])
{
  vector<int> arr = {5,2,6,8,4,5,9,10,7};
  cout << "Input: ";
  printArr(arr);
  cout << "Output: ";
  printArr(mergeSort(arr));
  return 0;
}
