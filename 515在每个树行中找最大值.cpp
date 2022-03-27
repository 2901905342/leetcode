//给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。

///思路 ：典型的BFS
#include "myhead.h"
//  Definition for a binary tree node.
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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> duilie;
        vector<int> res;
        if (root != nullptr) duilie.push(root);
        while (!duilie.empty()) {
            int d_size = duilie.size();
            int maxhang = -pow(2, 31);
            for (int i = 0; i < d_size; i++) {
                TreeNode* temp = duilie.front();
                duilie.pop();
                if (temp->val > maxhang) maxhang = temp->val;  //寻找每一行的最大值
                if (temp->left != nullptr) duilie.push(temp->left);
                if (temp->right != nullptr) duilie.push(temp->right);
            }
            res.push_back(maxhang);
        }
        return res;
    }
};