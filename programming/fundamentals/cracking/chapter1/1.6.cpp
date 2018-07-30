#include <iostream>
#include <string>
#include <vector>

/**
 * Question 
 *
 * Given an image represented by an NxN matrix, where each pixel in the image is
 * 4 bytes, write a method to rotate the image by 90 degrees. Can you do this in
 * place?
 *
 * A[][] = { {1,2,3,4},
 *           {2,1,4,3},
 *           {3,1,3,2},
 *           {4,4,1,1} };
 *
 * A[][] = { {4,3,2,1},
 *           {3,4,3,1},
 *           {2,1,1,4},
 *           {1,2,3,4} };
 * 
 * Approach
 * - Swap 4 coordinates each time
 * - Simple solution is to create new array and copy from one to the other. 
 * - To be more space efficient can use a single buffer to hold one value that
 *   is copied last.
 */

void printArray(int a[5][5], int size)
{
  for(int i = 0; i < size; i++)
  {
    for(int j = 0; j < size; j++)
    {
      std::cout << a[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

int main(int argc, const char *argv[])
{
  int a[5][5] = { {1,2,3,4,5},
                  {2,3,4,5,6},
                  {3,4,5,6,7},
                  {4,5,6,7,8},
                  {5,6,7,8,9} };

  printArray(a, 5);

  int length = 5-1;
  for(int i = 0; i <= length/2; i++)
  {
    for(int j = i; j < length-i; j++)
    {
      int tmp = a[i][j];

      a[i][j] = a[length-j][i];
      a[length-j][i] = a[length-i][length-j];
      a[length-i][length-j] = a[j][length-i];
      a[j][length-i] = tmp;
    }
  }

  printArray(a, 5);
  
  return 0;
}
