#include "TreeNode.h"
#include <iostream>
#include <queue>

using namespace std;

static void printDFS(TreeNode *node) {
  if(node == NULL) {
    return;
  }
  cout << node->val << endl;
  for(auto &child : node->children) {
    printDFS(child);
  }
}

static void printBFS(TreeNode *root) {
  queue<TreeNode*> q;
  q.push(root);
  while(!q.empty()) {
    TreeNode *n = q.front();
    cout << n->val << endl;
    for(auto &child : n->children) {
      q.push(child);
    }
    q.pop();
  }
}

int main(int argc, const char *argv[])
{
  //
  //     1
  //    2  4
  //   3
  // 
  // print DFS: 1 2 3 4
  // print BFS: 1 2 4 3
  //
  TreeNode node1(1), node2(2), node3(3), node4(4);
  node1.children.push_back(&node2);
  node1.children.push_back(&node4);
  node2.children.push_back(&node3);
  cout << "Print DFS" << endl << "---------" << endl;
  printDFS(&node1);
  cout << "Print BFS" << endl << "---------" << endl;
  printBFS(&node1);
  return 0;
}
