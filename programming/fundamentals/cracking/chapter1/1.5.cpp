#include <iostream>
#include <string>
#include <vector>
#include <sstream>

/**
 * Question 
 *
 * Implement a method to perform basic string compression using the counts of
 * repeated characters. For example, the string aabcccccaaa would become
 * a2b1c5a3. If the "compressed" string would not become small than the original
 * string, your method should return the original string
 */

/**
 * @return false if string is not compressable
 */
bool compress(std::string &input)
{
  std::stringstream output;
  char cur = input.at(0);
  int count = 1;
  for(int i = 1; i <= input.length(); i++)
  {
    if(i < input.length() && input[i] == cur)
    {
      count++;
    }
    else 
    {
      output << cur << count; 
      count = 1;
      cur = input[i];
    }
  }
  if(output.str().length() < input.length())
  {
    input = output.str();
    return true;
  }
  return false;
}


int main(int argc, const char *argv[])
{
  std::string str = "aabcccccaaa";
  const std::string output = "a2b1c5a3";
  bool ret = compress(str);

  std::cout << str << " ?= " << output << std::endl;
  if(str != output || !ret)
  {
    std::cout << "Not working";
  }
  else 
  {
    std::cout << "Ok!";
  }
  std::cout << std::endl;
  
  return 0;
}
