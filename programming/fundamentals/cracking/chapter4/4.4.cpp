#include <iostream>
#include <string>
#include <vector>
#include "../../trees/BinarySearchTree.h"
#include "../../linked_lists/SinglyLinkedList.h"

/**
 * Question 
 *
 * Given a binary tree, design an algorithm which creates a linked list of all
 * the nodes at each depth (e.g., if you have a tree with depth D, you'll have D
 * linked lists).
 *
 * Approach
 * - Do depth first traversal, using the level to append to the right linked
 *   list
 */

void toLinkedLists(BinaryTree::Node *node, 
                   std::vector<SinglyLinkedList> &linkedLists)
{
  static int level = 0;
  Node *n = new Node(node->value);
  if(linkedLists.size() <= level)
  {
    SinglyLinkedList list;
    linkedLists.push_back(list);
  }

  SinglyLinkedList &list = linkedLists.at(level);
  list.append(n);

  if(node->left != NULL)
  {
    level++;
    toLinkedLists(node->left, linkedLists);
    level--;
  }
  if(node->right != NULL)
  {
    level++;
    toLinkedLists(node->right, linkedLists);
    level--;
  }
}

int main(int argc, const char *argv[])
{
  BinarySearchTree tree;
  tree.insert(4);
  tree.insert(2);
  tree.insert(5);
  tree.insert(3);
  tree.insert(6);

  tree.print();

  std::vector<SinglyLinkedList> linkedLists;
  toLinkedLists(tree.root, linkedLists);

  std::vector<SinglyLinkedList>::iterator l;
  for(l = linkedLists.begin(); l != linkedLists.end(); ++l)
  {
    l->print(); 
  }
  
  return 0;
}
