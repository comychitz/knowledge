#include <iostream>
#include <string>
#include <vector>

/**
 * Question 
 *
 * Write an algorithm such that if an element in an MxN matrix is 0, its
 * entire row and column are set to 0.
 *
 * A[][] = { {1, 0, 1, 0},
 *           {1, 1, 1, 1},
 *           {0, 0, 0, 0},
 *           {1, 1, 1, 0},
 *           {0, 1, 0, 1} };
 *
 * Approaches
 * - A simple solution would be to create a new array and iterate through the
 *   original one. If a 0 is encountered, set the row and column to 0.
 *   - This is kind of inefficient as we may 0-out the same cells many times.
 * 
 * - A slightly better solution would be to keep track of the cells we have
 *   visited to prevent redundant work. This can be done by keeping an initial
 *   value that can be distinguished from the others.
 */


int main(int argc, const char *argv[])
{

  
  return 0;
}
