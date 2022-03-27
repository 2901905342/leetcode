//给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。

//////思路：利用队列辅助完成BFS(广度优先遍历）

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> duilie;
        if (root != nullptr) duilie.push(root);
        vector<vector<int>> res;
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
        return res;
    }
};