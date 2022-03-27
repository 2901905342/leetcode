//给定一个二叉树，找出其最小深度。
//最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
//说明：叶子节点是指没有子节点的节点。

///思路：广度优先遍历，找到第一个叶子节点(必然是最近叶子节点）就返回

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
    int minDepth(TreeNode* root) {
        queue<TreeNode* >duilie;
        int res = 0;
        if (root != nullptr) {
            duilie.push(root);
            res++;
        }
        while (!duilie.empty()) {
            int d_size = duilie.size();
            for (int i = 0; i < d_size; i++) {
                TreeNode* temp = duilie.front();
                duilie.pop();
                if (temp->left == nullptr && temp->right == nullptr) return res;
                if (temp->left) duilie.push(temp->left);
                if (temp->right) duilie.push(temp->right);
            }
            res++;
        }
        return res;
    }
};