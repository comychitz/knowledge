#include <iostream>
#include <string>
#include <vector>

/**
 * Question 
 *
 * Write a method that takes a pointer to a Node structure as a parameter and
 * returns a complete copy of the passed in data structure. The node data
 * structure contains two pointers to other Nodes.
 */

typedef struct Node {
  int value;
  Node *n1, *n2;
};

Node * copyNode(Node *in)
{
  if(in == NULL)
  {
    return NULL;
  }
  Node *out = new Node();
  out->value = in->value;
  out->n1 = copyNode(in->n1);
  out->n2 = copyNode(in->n2);
  return out;
}

int main(int argc, const char *argv[])
{

  
  return 0;
}
