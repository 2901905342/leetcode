//给你二叉树的根节点 root ，返回它节点值的 前序 遍历。
//前序遍历：按照访问根节点——左子树——右子树的方式遍历这棵树



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
        if (node == nullptr) return;
        res.push_back(node->val);//中
        dfs(node->left, res);//左
        dfs(node->right, res);//右
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        dfs(root, res);
        return res;
    }
};