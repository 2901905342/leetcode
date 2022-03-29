//给定一个二叉树，找出其最大深度。
//
//二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
//
//说明 : 叶子节点是指没有子节点的节点。

//果断采用深度优先遍历解题

#include "myhead.h"

/**
 * Definition for a binary tree node.*/
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
    int dfs(TreeNode* node) {
        if (node == nullptr) return 0;
        int Ldeep = dfs(node->left);
        int Rdeep = dfs(node->right);
        return max(Ldeep, Rdeep) + 1;
    }
    int maxDepth(TreeNode* root) {

        return dfs(root);

    }
};

/// <summary>
/// ///当然也可以使用BFS
/// </summary>
class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode* >duilie;
        int res = 0;
        if (root != nullptr) {
            duilie.push(root);
        }
        while (!duilie.empty()) {
            int d_size = duilie.size();
            for (int i = 0; i < d_size; i++) {
                TreeNode* temp = duilie.front();
                duilie.pop();
                if (temp->left != nullptr) duilie.push(temp->left);
                if (temp->right != nullptr) duilie.push(temp->right);
            }
            res++;
        }
        return res;
    }
};