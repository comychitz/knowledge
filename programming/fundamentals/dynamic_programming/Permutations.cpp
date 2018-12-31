#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> permutations(const string &in) {

  vector<string> perms;
  if(in.empty()) {
    return perms;
  }
  if(in.size() == 1) {
    perms.push_back(in);
    return perms;
  }
  if(in.size() == 2) {
    perms.push_back(in);
    string tmp = in;
    reverse(tmp.begin(), tmp.end());
    perms.push_back(tmp);
    return perms;
  }

  char c = in.at(0);
  string tmp = in.substr(1);
  vector<string> poss = permutations(tmp);

  for(auto &perm : poss) {
    for(size_t j = 0; j < perm.size(); j++) {
      string str(perm);
      str = str.insert(j, 1, c);
      perms.push_back(str);
    }
    perms.push_back(perm+c);
  }
  return perms;
}

int main(int argc, const char *argv[]) {

  vector<string> perms = permutations("abcdef");
  cout << perms.size() << " permutations:";
  for(auto &perm : perms) {
    cout << " " << perm;
  }
  cout << endl;
  return 0;
}
