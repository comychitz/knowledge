#include <iostream>
#include <unordered_map>

//
// Fibonacci number solved using dynamic programming
// 0, 1, 1, 2, 3, 5, 8 ...
//

int fib_(int n, std::unordered_map<int, int> &fibs)
{
  if(n <= 1)
  {
    return 1;
  }
  std::unordered_map<int,int>::iterator f;
  if((f = fibs.find(n)) != fibs.end())
  {
    return f->second;
  }
  int ret = (fib_(n-1, fibs) + fib_(n-2, fibs));
  fibs[n] = ret;
  return ret;
}

int fibonacci(int n)
{
  std::unordered_map<int, int> fibs; 
  return fib_(n, fibs);
}

int main( int argc, const char *argv[] )
{
  int n = 40; 
  std::cout << "Fibonacci of " << n << " = " << fibonacci(n) << std::endl;
  return 0;
}
