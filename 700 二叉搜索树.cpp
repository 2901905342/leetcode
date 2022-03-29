//给定二叉搜索树（BST）的根节点和一个值。 你需要在BST中找到节点值等于给定值的节点。 返回以该节点为根的子树。 如果节点不存在，则返回 NULL。
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
      TreeNode* searchBST(TreeNode* root, int val) {
          if (root == nullptr) return NULL;
          if (root->val == val) return root;
          if (root->val > val) return searchBST(root->left, val);
          else return searchBST(root->right, val);

      }
  };