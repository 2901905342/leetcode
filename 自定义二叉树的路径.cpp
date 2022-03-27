///给定一棵二叉树，请返回根节点到所有叶子节点的路径
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
      void dfs(TreeNode* node, vector<int>& path, vector<vector<int>>& res) {
          path.push_back(node->val);
          if (node->left == nullptr && node->right == nullptr) {
              res.push_back(path);
              return;
          }
          if (node->left != nullptr) {
              dfs(node->left, path, res);
              path.pop_back();
          }
          if (node->right != nullptr) {
              dfs(node->right, path, res);
              path.pop_back();
          }
      }
      vector<vector<int>> binaryTreePaths(TreeNode* root) {
          vector<vector<int>> res;
          vector<int> path;
          if (root == nullptr) return res;
          dfs(root, path, res);
          return res;

      }
  };