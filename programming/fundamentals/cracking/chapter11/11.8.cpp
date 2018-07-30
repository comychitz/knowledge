#include <iostream>
#include <string>
#include <vector>

/**
 * Question 
 *
 * Imagine you are reading in a stream of integers. Periodically, you wish to be
 * able to look up the rank of a number x (the number of values less than or
 * equal to x). Implement the data structures and algorithms to support these
 * operations. That is, implement the method track(int x), which is called when
 * each number is generated, and the method getRankOfNumber(int x), which
 * returns the number of values less than or equal to x (not including x
 * itself).
 * EXAMPLE
 * stream (in order of appearance): 5,1,4,4,5,9,7,13,3
 * getRankOfNumber(1) = 0
 * getRankOfNumber(3) = 1
 * getRankOfNumber(4) = 3 
 *
 * Approach:
 *   - Need to keep values sorted to be able to quickly get rank of number
 *   - track() will add the new value to the sorted list
 *
 * Solution #1:
 *   - merge sort new values into list each time - O(nlog(n)) per insert
 *   - O(n) for getting rank
 *
 * Solution #2:
 *   - keep list of pairs, as values come in increment the rank (O(n) per
 *   insert).
 *   - O(n) for getting rank
 *
 * Solution #3:
 *   - keep map of values and their rank - insert would be O(n)
 *   - O(1) for getting rank
 *
 * Solution #4:
 *   - use a linked list for inserting - O(n) per insert
 *   - O(n) for getting rank, but less space used.
 */


int main(int argc, const char *argv[])
{

  
  return 0;
}
