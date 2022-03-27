//给定一个非空二叉树的根节点 root, 以数组的形式返回每一层节点的平均值。
//与实际答案相差 10 - 5 以内的答案可以被接受。

///////////////本题思路与102二叉树的层序遍历一致，注意数字类型转换
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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> duilie;
        if (root != nullptr) duilie.push(root);
        while (!duilie.empty()) {
            int d_size = duilie.size();
            double d_sum = 0;
            for (int i = 0; i < d_size; i++) {
                TreeNode* temp = duilie.front();
                duilie.pop();
                d_sum += temp->val;  //存储每层的累和
                if (temp->left != nullptr) duilie.push(temp->left);
                if (temp->right != nullptr) duilie.push(temp->right);
            }
            res.push_back(d_sum / d_size);
        }
        return res;
    }
};