#include <iostream>
#include <string>
#include <vector>

/**
 * Question 
 *
 * Write an algorithm to find the 'next' node (i.e., in-order successor) of a
 * given node in a binary search tree. You may assume that each node has a link
 * to its parent.
 *
 *     4
 *    2 6
 *   1 5 7
 *
 *  1 : 2
 *  4 : 5
 *  6 : 7 
 */

class Node 
{
  public:
    int value;
    Node *parent, *left, *right;

    Node(int v) : value(v), parent(NULL), left(NULL), right(NULL) { }

    ~Node() { }
};

Node *min(Node *n)
{
  if(n->left == NULL)
  {
    return n;
  }
  return min(n->left);
}


Node *findNext(Node *n)
{
  Node *next = NULL;
  if(n->parent == NULL)
  {
    if(n->right != NULL)
    {
      next = min(n->right);
    }
  }
  else 
  {
    Node *parent = n->parent;
    if(n->value <= n->parent->value)
    { //
      // on the left side, so the next should be the root if 
      // we have no children, else the min of the right subtree
      //
      if(n->right == NULL)
      {
        next = n->parent;
      }
      else 
      {
        next =min(n->right);
      }
    }
    else
    { //
      // on the right side, so the next should be the min of the right subtree
      // else, the root if we are on the left side of the tree.
      //
      Node *root = n->parent;
      while(root->parent != NULL)
      {
        root = root->parent;
      }

      if(n->right == NULL)
      {
        if(n->value <= root->value)
        {
          next = root;
        }
      }
      else 
      {
        next = min(n->right);
      }
    }
  }

  std::cout << "Next of " << n->value << " is ";
  if(next)
  {
    std::cout << next->value;
  }
  else 
  {
    std::cout << "(null)";
  }
  std::cout << std::endl;
  return next;
}

int main(int argc, const char *argv[])
{
  Node n(1), n2(2), n3(10), n4(14), n5(15), n6(5), n7(7), n8(6);

  n3.left = &n6;
  n6.parent = &n3;
  n3.right = &n4;
  n4.parent = &n3;
  n6.left = &n2;
  n2.parent = &n6;
  n6.right = &n7;
  n7.parent = &n6;
  n7.left = &n8;
  n8.parent = &n7;

  Node *next = findNext(&n3);
  next = findNext(&n6);
  next = findNext(&n4);
  next = findNext(&n2);
  next = findNext(&n7);
  next = findNext(&n8);

  return 0;
}
