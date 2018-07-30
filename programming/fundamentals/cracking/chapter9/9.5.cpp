#include <iostream>
#include <string>
#include <vector>

/**
 * Question 
 *
 * Write a method to compute all permutations of a string of unique characters.
 */

//
// abc = abc, acb, bca, bac, cab, cba (6)
//

std::vector<std::string> permString(const std::string &str)
{
  std::vector<std::string> perms;
  if(str.size() == 0)
  {
    return perms;
  }
  else if(str.size() == 1)
  {
    perms.push_back(str);
    return perms;
  }

  char c = str[0];
  std::vector<std::string> perms2 = permString(str.substr(1));

  std::vector<std::string>::iterator p;
  for(p = perms2.begin(); p != perms2.end(); ++p)
  {
    int size = p->size();
    for(int i = 0; i <= size; ++i)
    {
      std::string perm = *p;
      perm.insert(i, 1, c);
      perms.push_back(perm);
    }
  }

  return perms;
}


int main(int argc, const char *argv[])
{
  std::string input = "abcd";
  std::vector<std::string> perms = permString(input);

  std::vector<std::string>::iterator p;
  for(p = perms.begin(); p != perms.end(); ++p)
  {
    std::cout << *p << std::endl;
  }
  std::cout << "Total num: " << perms.size() << std::endl;
  return 0;
}
