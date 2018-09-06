#include <iostream>
#include <vector>
#include <map>

using namespace std;

// value to weight
typedef map<int,int> Items;

int fillKnapsack(int W, int V, Items &items)
{
  if(W == 0 || items.empty())
  {
    return V;
  }

  int max = 0;
  Items copy = items;
  for(Items::iterator item = items.begin(); item != items.end(); ++item)
  {
    copy.erase(item->first);
    if(W - item->second >= 0)
    {
      max = std::max(max, fillKnapsack(W-item->second, V+item->first, copy));
    }
  }
  return max;
}

int main( int argc, const char *argv[] )
{
  // example 1
  Items items;
  items[60] = 10;
  items[100] = 20;
  items[120] = 30;
  int W = 50;
  cout << "Value of items to steal: " << fillKnapsack(W, 0, items) << endl;

  // example 2
  Items items2;
  items2[10] = 5;
  items2[40] = 4;
  items2[30] = 6;
  items2[50] = 3;
  int W2 = 10;
  cout << "Value of items to steal: " << fillKnapsack(W2, 0, items2) << endl;
  
  // example 3
  Items items3;
  items3[100] = 3;
  items3[20] = 2;
  items3[60] = 4;
  items3[40] = 1;
  int W3 = 5;
  cout << "Value of items to steal: " << fillKnapsack(W3, 0, items3) << endl;

  return 0;
}
