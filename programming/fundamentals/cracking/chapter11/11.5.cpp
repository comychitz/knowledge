#include <iostream>
#include <string>
#include <vector>

/**
 * Question 
 *
 * Given a sorted array of strings which is interspersed with empty strings,
 * write a method to find the location of a given string.
 * EXAMPLE
 * Input: find "ball" in {"at", "", "", "", "ball", "", "", "car", "", "",
 * "dad", "", ""}
 * Output: 4
 *
 * Solution #1:
 * - Iterate through all: O(n)
 *
 * Solution #2:
 * - Modified Binary Search - when choosing middle, needs to be a non-empty
 *   string. If empty, continue left until find 
 */

int binarySearch(const std::string &str,
                 const std::vector<std::string> &input, 
                 int start, int end)
{
  if(start > end)
  {
    return -1;
  }

  int middle = start + (end-start)/2;
  while(input.at(middle).empty() && middle < end)
  {
    middle++;
  }

  if(middle == end && input.at(middle).empty())
  { // go to the left 
    middle = start + (end-start)/2;
    while(input.at(middle).empty() && middle > start)
    {
      middle--;      
    }
  }

  if(str == input.at(middle))
  {
    return middle;
  }
  if(str < input.at(middle))
  {
    return binarySearch(str, input, start, middle-1);
  }
  return binarySearch(str, input, middle+1, end);
  
}

int findString(const std::string &str,
               const std::vector<std::string> &input)
{
  int ret = binarySearch(str, input, 0, input.size());
  std::cout << "Found " << str << " at " << ret << std::endl;
  return ret;
}


int main(int argc, const char *argv[])
{
  std::vector<std::string> input;
  input.push_back("at");
  input.push_back("");
  input.push_back("");
  input.push_back("");
  input.push_back("ball");
  input.push_back("");
  input.push_back("");
  input.push_back("car");
  input.push_back("");
  input.push_back("");
  input.push_back("dad");
  input.push_back("");
  input.push_back("");

  findString("ball", input);
  findString("at", input);
  findString("dad", input);
  findString("car", input);
  findString("cameron", input);

  return 0;
}
