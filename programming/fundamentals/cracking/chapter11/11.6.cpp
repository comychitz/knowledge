#include <iostream>
#include <string>
#include <vector>

/**
 * Question 
 *
 * Given an MxN matrix in which each row and each column is sorted in ascending
 * order, write a method to find an element.
 *
 * [[1,2,3],
 *  [3,5,7],
 *  [8,9,10]]
 *
 *  Approaches:
 *  - Create one list of each row + column, then binary search in it
 *    - O(M+N) to create list then O(log(M+N)) to search it, for each M
 *    - but each time we move down and in 
 *
 *  - Can create one big sorted list and then binary search in it. This would
 *  take a lot more space
 *
 *  - Iterate backwards through matrix, eliminating columns and rows as soon as
 *  possible
 */


int main(int argc, const char *argv[])
{
  int matrix[4][5] = {{1,5,7,9,10},
                      {4,6,11,22,33},
                      {8,23,30,31,35},
                      {10,30,33,41,55}};

  int toFind = 30;

  int row = 0, column = 4;
  while(row < 4 && column >= 0)
  {
    if(matrix[row][column] == toFind)
    {
      break;
    }
    else if(matrix[row][column] < toFind)
    {
      row++;
    }
    else
    {
      column--;
    }
  }

  std::cout << "Found " << toFind << " at (" << row << "," << column << ")" << std::endl;
  
  return 0;
}
