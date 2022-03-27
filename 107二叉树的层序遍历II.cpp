//给你二叉树的根节点 root ，返回其节点值 自底向上的层序遍历 。 
//（即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）

///////思路  ：跟102题一模一样，只是最后多加一个reverse函数

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> duilie;
        vector<vector<int>> res;
        if (root != nullptr) duilie.push(root);
        while (!duilie.empty()) {
            int d_size = duilie.size();
            vector<int> vec;
            for (int i = 0; i < d_size; i++) {
                // 这里一定要使用固定大小d_size，不要使用duilie.size()，因为duilie.size是不断变化的
                TreeNode* temp = duilie.front();
                duilie.pop();
                vec.push_back(temp->val);
                if (temp->left != nullptr) duilie.push(temp->left);
                if (temp->right != nullptr) duilie.push(temp->right);
            }
            res.push_back(vec);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};