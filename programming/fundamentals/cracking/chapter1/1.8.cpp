#include <iostream>
#include <string>
#include <vector>

/**
 * Question 
 *
 * Assume you haev a method isSubstring() which check is one word is a substring
 * of another. Given two strings, s1 and s2, write code to check if s2 is a
 * rotation of s1 using only one call to isSubstring (eg. "waterbottle" is a
 * rotation of "erbottlewat").
 *
 * Approach
 *
 * The secret to rotations is that placing two copies of the rotated array back
 * to back will result in the non-rotated array somewhere in the middle(!)
 */

bool isRotation(const std::string &s1, const std::string &s2)
{
  std::string str = s1+s1;

  return str.find(s2) == std::string::npos ? false : true;
}

int main(int argc, const char *argv[])
{
  std::string s1 = "erbottlewat";
  std::string s2 = "waterbottle";

  std::cout << isRotation(s1, s2) << std::endl;
  
  return 0;
}
