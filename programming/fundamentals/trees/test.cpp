#include "BinarySearchTree.h"

int main( int argc, const char *argv[] )
{
  BinarySearchTree tree;

  tree.insert(10);
  tree.insert(8);
  tree.insert(12);
  tree.insert(5);
  tree.insert(9);
  tree.insert(11);
  tree.insert(4);
  tree.insert(3);

  tree.print();
  tree.printDF();
  tree.printInOrder();

  std::cout << "Tree depth: " << tree.depth() << std::endl;
  
  return 0;
}
