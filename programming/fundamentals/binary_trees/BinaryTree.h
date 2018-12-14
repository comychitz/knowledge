#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

#include <iostream>
#include <queue>

class BinaryTree
{
  public:
    class Node
    {
      public:
        Node() : left(NULL), right(NULL), value(0) { }

        Node(int val) : left(NULL), right(NULL), value(val) { }

        virtual ~Node() { }

        Node *left, *right;
        int value;
    };
    typedef std::queue<Node*> NodeQueue;

    Node *root;

    BinaryTree() : root(NULL) { }

    virtual ~BinaryTree() { }

    /**
     * insert a node to the tree
     */
    virtual void insert(int value) = 0;
 
    /**
     * delete a node from the tree
     */
    virtual void remove(Node *node) = 0;

    /**
     * determine depth of the binary tree
     */
    int depth() const
    {
      int depth = 0;

      if(root != NULL)
      {
        depth = 1;
        depth = getTreeDepth_(root, depth);
      }
      return depth;
    } 

    /**
     * print the binary tree breadth-first
     */
    virtual void print() const
    {
      if(root == NULL)
      {
        std::cout << "(empty)";
        return;
      }

      NodeQueue q;
      std::cout << root->value << " ";
      q.push(root);

      while(!q.empty())
      {
        Node *n = q.front();
        if(n->left != NULL)
        {
          std::cout << n->left->value << " ";
          q.push(n->left);
        }
        if(n->right != NULL)
        {
          std::cout << n->right->value << " ";
          q.push(n->right);
        }
        q.pop();
      }
      std::cout << std::endl;
    }

    /**
     * print the binary tree depth-first
     */
    virtual void printDF() const
    {
      printDF_(root, 0);
      std::cout << std::endl;
    }

    /**
     * print the binary tree, traversing it in order
     */
    virtual void printInOrder() const
    {
      printIO_(root);
      std::cout << std::endl;
    }

  private:
    void printIO_(Node *n) const
    {
      if(n->left != NULL)
      {
        if(n->left->left != NULL ||
           n->left->right != NULL)
        {
          printIO_(n->left);
        }
        else 
        {
          std::cout << n->left->value << " ";
        }
      }
      std::cout << n->value << " ";
      if(n->right != NULL)
      {
        if(n->right->left != NULL ||
           n->right->left != NULL)
        {
          printIO_(n->right);
        }
        else 
        {
          std::cout << n->right->value << " ";
        }
      }
    }

    void printDF_(Node *n, int depth) const
    {
      std::cout << n->value << " (depth: " << depth << ")" << std::endl;
      if(n->left)
      {
        printDF_(n->left, depth+1);
      }
      if(n->right)
      {
        printDF_(n->right, depth+1);
      }
    }

    int getTreeDepth_(Node *node, int depth) const
    {
      if(node->left != NULL || node->right != NULL)
      {
        depth++;
      }
      int d1 = depth, d2 = depth;
      if(node->left != NULL)
      {
        d1 = getTreeDepth_(node->left, depth);
      }
      if(node->right != NULL)
      {
        d2 = getTreeDepth_(node->right, depth);
      }
      return d1 > d2 ? d1 : d2;
    }
};

#endif
