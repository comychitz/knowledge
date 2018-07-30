#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>

/**
 * Question 
 *
 * Write a method to replace all spaces in a string with '%20'. You may assume
 * that the string has sufficient space at the end of the string to hold the
 * additional characters, and that you are given the "true" length of the
 * string.
 */

void replace(std::string &input)
{
  const std::string r = "%20";
  bool seenChar = false;
  unsigned end = input.length()-1;
  for(int i = input.length()-1; i >= 0; i--)
  {
    if(std::isspace(input.at(i)))
    {
      if(seenChar)
      {
        for(int j = 0; j < 3; j++)
        {
          input[end--] = r.at(2-j);
        }
        seenChar = false;
      }
    }
    else if(end-1 > i)
    {
      input[end--] = input.at(i);
      input[i] = ' ';
      seenChar = true;
    }
    std::cout << input<< std::endl;
  }
}


int main(int argc, const char *argv[])
{
  
  std::string str = "Mr John Smith    ";
  
  std::cout << str << std::endl;

  replace(str);

  std::cout << str << std::endl;

  return 0;
}
