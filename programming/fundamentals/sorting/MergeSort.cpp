#include <iostream>
#include <vector>

static void split(const std::vector<int> &in,
                  std::vector<int> &a1,
                  std::vector<int> &a2)
{
  for(unsigned i = 0; i < in.size(); ++i)
  {
    if(i <= (in.size()-1)/2)
    {
      a1.push_back(in.at(i));
    }
    else 
    {
      a2.push_back(in.at(i));
    }
  }
}

static std::vector<int> merge(const std::vector<int> &a,
                              const std::vector<int> &b)
{
  std::vector<int> out;
  unsigned i = 0, j = 0;
  while(i < a.size() && j < b.size())
  {
    if(a.at(i) <= b.at(j))
    {
      out.push_back(a.at(i));
      i++;
    }
    else 
    {
      out.push_back(b.at(j));
      j++;
    }
  }

  while(i < a.size())
  {
    out.push_back(a.at(i));
    i++;
  }
  while(j < b.size())
  {
    out.push_back(b.at(j));
    j++;
  }
  return out;
}

std::vector<int> mergeSort(std::vector<int> &in)
{
  if(in.size() == 1)
  {
    return in;
  }
  std::vector<int> a1, a2, sortedA1, sortedA2;

  split(in, a1, a2);
  sortedA1 = mergeSort(a1);
  sortedA2 = mergeSort(a2);
  return merge(sortedA1, sortedA2);
}

void print(const std::vector<int> &in)
{
  std::vector<int>::const_iterator i;
  for(i = in.begin(); i != in.end(); ++i)
  {
    std::cout << *i << " ";
  }
  std::cout << std::endl;
}

int main( int argc, const char *argv[] )
{
  std::vector<int> values, sorted;

  values.push_back(5);
  values.push_back(3);
  values.push_back(9);
  values.push_back(1);
  values.push_back(2);
  values.push_back(12);

  std::cout << "Before sorting: ";
  print(values);

  sorted = mergeSort(values);

  std::cout << "After sorting: ";
  print(sorted);
  
  return 0;
}
