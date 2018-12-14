#ifndef _TREE_HODE_H_
#define _TREE_HODE_H_

#include <vector>

class TreeNode {
  public:
    TreeNode() : val(0) { }

    TreeNode(int x) : val(x) {  }

    virtual ~TreeNode() { }

    int val;
    std::vector<TreeNode*> children;
};

#endif
