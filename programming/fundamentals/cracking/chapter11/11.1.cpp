#include <iostream>
#include <string>
#include <vector>

/**
 * Question 
 *
 * You are given two sorted arrays, A and B, where A has a large enough buffer
 * at the end to hold B. Write a method to merge B into A in sorted order.
 *
 * Approach
 * A: [1,3,5,_,_]
 * B: [2,4]
 *
 * Approach #1:
 * - backwards merge sort
 */

void mergeSorted(int a[], int capA, int sizeA,
                int b[], int sizeB)
{
  int indexB = sizeB-1, indexA = sizeA-1;
  while(indexB >= 0 && indexA >= 0)
  {
    if(a[indexA] >= b[indexB])
    {
      a[capA-1] = a[indexA--];
    }
    else
    {
      a[capA-1] = b[indexB--];
    }
    capA--;
  }

  // put remaining entries of a or b
  while(indexA >= 0)
  {
    a[capA-1] = a[indexA--];
    capA--;
  }

  while(indexB >= 0)
  {
    a[capA-1] = b[indexB--];
    capA--;
  }
}


int main(int argc, const char *argv[])
{
  int a[5] = {1,3,5,0,0};
  int b[2] = {2,4};

  mergeSorted(a, 5, 3, b, 2);

  for(int i = 0; i < 5; i++)
  {
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;
  
  return 0;
}
