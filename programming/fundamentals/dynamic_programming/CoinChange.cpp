#include <iostream>
#include <set>
#include <vector>
#include <map>

using namespace std;

int coinChange(int val, int change) {
  val -= change;
  if(val == 0) {
    return 1;
  } else if(val < 0) {
    return 0;
  }
  int ways = 0;
  set<int> coins = {25,10,5,1};
  for(auto &coin : coins) {
    if(change > coin) {
      continue;
    }
    ways += coinChange(val, coin);
  }
  return ways;
}

int main(int argc, const char *argv[])
{
  int val = 100;
  int ways = coinChange(val, 0);
  cout << "Number of ways to change " << val << " cents: " << ways << endl;
  return 0;
}
