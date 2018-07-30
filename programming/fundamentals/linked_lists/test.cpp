#include "SinglyLinkedList.h"

int main( int argc, const char *argv[] )
{
  
  SinglyLinkedList list;
  Node n1(1), n2(3), n3(5);
  list.append(&n1);
  list.append(&n2);
  list.append(&n3);

  list.print();

  list.reverse();

  list.print();

  return 0;
}
