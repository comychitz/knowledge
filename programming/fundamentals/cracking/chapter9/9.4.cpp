#include <iostream>
#include <string>
#include <vector>
#include <set>

/**
 * Question 
 *
 * Write a method to return all subsets of a set.
 */

std::set<std::set<int> > getSubsets(std::set<int> &s)
{
  std::set<std::set<int> > subsets;

  if(s.empty())
  {
    return subsets;
  }
  else if(s.size() == 1)
  {
    subsets.insert(s);
    return subsets;
  }

  subsets.insert(s);

  std::set<int>::iterator iter;
  for(iter = s.begin(); iter != s.end(); ++iter)
  {
    std::set<int> s1, s2 = s;
    s1.insert(*iter);
    s2.erase(*iter);
    std::set<std::set<int> > subsets2 = getSubsets(s2);
    std::set<std::set<int> >::iterator iter2;
    for(iter2 = subsets2.begin(); iter2 != subsets2.end(); ++iter2)
    {
      subsets2.insert(s1);
    }
    subsets.insert(subsets2.begin(), subsets2.end());
  }
  return subsets;
}


int main(int argc, const char *argv[])
{

  std::set<int> s;
  s.insert(1);
  s.insert(2);
  s.insert(3);
  s.insert(4);

  std::set<std::set<int> > subsets = getSubsets(s);

  std::set<std::set<int> >::iterator iter;
  for(iter = subsets.begin(); iter != subsets.end(); ++iter)
  {
    std::cout << "{ ";
    std::set<int>::const_iterator iter2;
    for(iter2 = iter->begin(); iter2 != iter->end(); ++iter2)
    {
      std::cout << *iter2 << " ";
    }
    std::cout << " }, ";
  }
  std::cout << std::endl;
  
  return 0;
}
