#include <iostream>
#include <string>
#include <vector>
#include "../../linked_lists/SinglyLinkedList.h"

/**
 * Question 
 *
 * Write code to remove duplicates from an unsorted linked list.
 * FOLLOW UP
 * How would you solve this problem if a temporary buffer isn't allowed?
 *
 * Approaches:
 * - Keep a list/set of the ones we've seen O(n)
 *   or
 * - Iterate through all for each one O(n^2)
 */

void removeDuplicates(SinglyLinkedList &list)
{
  Node *cur = list.first;
  while(cur->next != NULL)
  {
    Node *next = cur;
    while(next != NULL && next->next != NULL)
    {
      if(cur->value == next->next->value)
      {
        next->next = next->next->next;
      }
      next = next->next;
    }
    cur = cur->next;
  }
}

int main(int argc, const char *argv[])
{
  //
  // 3->4->3->5->3;
  //
  SinglyLinkedList list;
  Node n(3), n2(4), n3(3), n4(5), n5(3);

  list.append(&n);
  list.append(&n2);
  list.append(&n3);
  list.append(&n4);
  list.append(&n5);

  list.print();

  removeDuplicates(list);

  list.print();
  
  return 0;
}
