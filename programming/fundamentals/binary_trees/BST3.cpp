#include <queue>
#include <cmath>
#include <iostream>

using namespace std;

class BST {
  public:
    class Node {
      public:
        explicit Node(int v) : val(v), left(NULL), right(NULL), parent(NULL) { }

        ~Node() { }

        void addLeft(Node *n) {
          if(!n) {
            return;
          }
          left = n;
          n->parent = this;
        }

        void addRight(Node *n) {
          if(!n) {
            return;
          }
          right = n;
          n->parent = this;
        }

        void rotateRight() {
          // save copy of left node into temporary node, then perform
          // rotation
          // TODO


        }

        int val;
        Node *left, *right, *parent;
    };

    Node *root;

    explicit BST(Node *r) : root(r) { }

    ~BST() { }

    void insert(Node *n) { 
      insert_(n, root);
    }

    void printBF() {
      if(!root) {
        return;
      }
      queue<Node*> q;
      q.push(root);

      int level = 0;
      int levelCount = pow(2, level);
      int count = 0;


      while (!q.empty()) {
        Node *cur = q.front();
        if(!cur) {
          cout << " ";
        } else {
          cout << cur->val << " ";
          if(cur->left) {
            q.push(cur->left);
          } else {
            q.push(NULL);
          }
          if(cur->right) {
            q.push(cur->right);
          } else  {
            q.push(NULL);
          }
        }
        count++;
        if(count >= levelCount) {
          cout << endl;
          count = 0;
          level++;
          levelCount = pow(2, level);
        }
        q.pop();
      }
      cout << endl;
    }

  private:
    void insert_(Node *n, Node* &start) {
      if(!start) {
        start = n;
        return;
      }
      if(n->val > start->val) {
        insert_(n, start->right);
      } else {
        insert_(n, start->left);
      }
    }
};

int main(int argc, const char *argv[])
{
  BST::Node n1(1), n2(2), n3(3), n4(4), n5(5);
  BST tree(&n3);

  tree.insert(&n1);
  tree.insert(&n2);
  tree.insert(&n4);
  tree.insert(&n5);

  tree.printBF();

  return 0;
}
