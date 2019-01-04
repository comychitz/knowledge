#include <iostream>
#include <vector>
#include <set>

using namespace std;

static void printSet(const set<int> &s) {

  cout << "{ ";
  for(auto &i : s) {
    cout << i << " ";
  }
  cout << "}" << endl;
}

vector<set<int> > getSubsets(const set<int> &s) {

  vector<set<int> > subsets;
  if(s.empty()) {
    return subsets;
  }

  if(s.size() == 1) {
    subsets.push_back(s);
    return subsets;
  }

  for(auto i = s.begin(); i != s.end(); ++i) {
    auto ii = i;
    ii++;
    set<int> s2(ii, s.end());

    vector<set<int> > tmp = getSubsets(s2);
    subsets.push_back({*i});

    for(auto &t : tmp) {
      t.insert(*i);
      subsets.push_back(t);
    }
  }
  return subsets;
}

int main( int argc, const char *argv[] )
{
  set<int> input = {1,2,3};
  vector<set<int> > subsets = getSubsets(input);

  for(auto &subset : subsets) {
    printSet(subset);
  }
  
  return 0;
}
