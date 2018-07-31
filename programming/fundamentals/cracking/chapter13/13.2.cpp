#include <iostream>
#include <string>
#include <vector>

/**
 * Question 
 *
 * Compare and contrast a hash table and an STL map. How is a hash table
 * implemented? If the number of inputs is small, which data structure options
 * can be used instead of a hash table?
 *
 * - STL map is actually a binary tree, because the keys are sorted based on a
 *   strict-weak ordering comparison function. Lookup is log(n) while a
 *   hash_table lookup is O(1)
 *
 * - Hash table is implemented by using a hash function that returns an index in
 *   the underlying array using the given input. 
 *
 * - If number of inputs is small, a simple vector or list may do.
 */


int main(int argc, const char *argv[])
{

  
  return 0;
}
