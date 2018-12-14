#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int fillKnapsack(int W, int val, vector<int> &values, vector<int> &weights, int index, int choice) {

  if(choice >= 0) {
    W -= weights.at(choice);
    if(W < 0) {
      return val;
    } 
    val += values.at(choice);
    if(W == 0) {
      return val;
    }
  }
  int max = -1;
  for(int i = index; i < values.size(); i++) {
    max = std::max(max, std::max(fillKnapsack(W, val, values, weights, i+1, -1), 
                                 fillKnapsack(W, val, values, weights, i+1, i)));
  }
  return max;
}

int main(int argc, const char *argv[])
{
  int W = 50;
  vector<int> values = {60, 100, 120};
  vector<int> weights = {10, 20, 30};
  int maxVal = fillKnapsack(W, 0, values, weights, 0, -1);
  cout << maxVal << endl;

  W = 25;
  values = {24, 18, 18, 10};
  weights = {24, 10, 10, 7};
  maxVal = fillKnapsack(W, 0, values, weights, 0, -1);
  cout << maxVal << endl;
  return 0;
}
