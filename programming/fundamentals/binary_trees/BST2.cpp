#include <iostream>
#include <queue>

using namespace std;

class BST {
  public:
  class Node {
    public:
      Node(int v) : left(NULL), right(NULL), val(v) { }

      ~Node() { }

      Node *left, *right;
      int val;
  };

  BST(Node &r) : root(&r) { }

  ~BST() { }

  Node *root;

  void printInOrder() {
    printInOrder_(root);
  }

  void printPreOrder() {
    printPreOrder_(root);
  }

  void printPostOrder() {
    printPostOrder_(root);
  }

  void printBFS() {

    if(!root) {
      return;
    }
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
      Node *node = q.front();
      cout << node->val << endl;
      if(node->left) {
        q.push(node->left);
      }
      if(node->right) {
        q.push(node->right);
      }
      q.pop();
    }
  }

  void printDFS() {
    printDFS_(root);
  }

  private:
    void printDFS_(Node *node) {
      if(!node) {
        return;
      }

      cout << node->val << endl;

      printDFS_(node->left);

      printDFS_(node->right);
    }
    
    void printPostOrder_(Node *node) {
      if(!node) {
        return;
      }
      printPostOrder_(node->left);

      printPostOrder_(node->right);

      cout << node->val << endl;
    }

    void printPreOrder_(Node *node) {
      if(!node) {
        return;
      }
      cout << node->val << endl;

      printPreOrder_(node->left);

      printPreOrder_(node->right);
    }

    void printInOrder_(Node *node) {
      if(!node) {
        return;
      }

      if(!node->left && !node->right) {
        cout << node->val << endl;
        return;
      }
      printInOrder_(node->left);

      cout << node->val << endl;

      printInOrder_(node->right);
    }
};

int main( int argc, const char *argv[] )
{
  BST::Node n1(1), n2(2), n3(3), n4(4), n5(10), n6(15), n7(11);
  BST bst(n4);

  n4.right = &n5;
  n4.left  = &n2;
  n2.right = &n3;
  n2.left  = &n1;
  n5.right = &n7;
  n7.right = &n6;

  cout << "In order:" << endl;
  bst.printInOrder();

  cout << endl << "Pre order: " << endl;
  bst.printPreOrder();

  cout << endl << "Post order: " << endl;
  bst.printPostOrder();

  cout << endl << "Breadth-first: " << endl;
  bst.printBFS();

  cout << endl << "Depth-first: " << endl;
  bst.printDFS();

  return 0;
}
