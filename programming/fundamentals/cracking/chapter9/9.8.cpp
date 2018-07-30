#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

/**
 * Question 
 *
 * Given an infinite number of quarters (25 cents), dimes (10 cents), nickels (5
 * cents) and pennies (1 cent), write code to calculate the number of ways to
 * represent n cents.
 *
 * 8 cents = 3x 1cent + 5cents, 8x 1cent => 2 total ways
 * 10 cents = 2x 5cents, 10x 1cent, 5cents + 5x 1cent, 10cents => 4 total ways
 */

int giveChange_(int n, int c)
{ 
  n = n-c;
  
  if(n == 0)
  {
    return 1;
  }
  else if(n < 0)
  {
    return 0;
  }
  int total = 0;
  if(c <= 1)
  {
    total += giveChange_(n, 1);
  }
  if(c <= 5)
  {
    total += giveChange_(n, 5);
  }
  if(c <= 10)
  {
    total += giveChange_(n, 10);
  }
  if(c <= 25)
  {
    total += giveChange_(n, 25);
  }
  return total;
}

int giveChange(int n)
{
  int total = 0;
  total = giveChange_(n, 1);
  total += giveChange_(n, 5);
  total += giveChange_(n, 10);
  total += giveChange_(n, 25);
  return total;
}


int main(int argc, const char *argv[])
{
  int n = 8;
  std::cout << "Total ways to give " << n << " cents: " << giveChange(n) << std::endl;

  n = 10;
  std::cout << "Total ways to give " << n << " cents: " << giveChange(n) << std::endl;

  n = 100;
  std::cout << "Total ways to give " << n << " cents: " << giveChange(n) << std::endl;
  
  return 0;
}
