#include <iostream>
#include <string>
#include <vector>
#include "../../linked_list/SinglyLinkedList.h"

/**
 * Question 
 *
 * Write code to partition a linked list around a value x, such that all nodes
 * less than x come before all nodes greater than or equal to x.
 *
 * Input: 2->6->8->1->4->10
 * Output: 4->1->2->6->8->10
 *
 * Approach
 * - Iterate through list, if haven't seen x, and current value is less than, do
 *   nothing. If current val is greater than, append to end of list. If we have
 *   seen x, and value is less than prepend, else if greater do nothing.
 */


int main(int argc, const char *argv[])
{

  
  return 0;
}
