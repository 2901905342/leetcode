//给定一个二叉树，返回它的 后序 遍历。
//按照访问左子树——右子树——根节点的方式遍历这棵树

#include "myhead.h"
 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    void dfs(TreeNode* node, vector<int>& res) {
        if (node == nullptr)  return;
        dfs(node->left, res);  //左
        dfs(node->right, res);  //右
        res.push_back(node->val); //中
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        dfs(root, res);
        return res;
    }
};