//����һ���ǿն������ĸ��ڵ� root, ���������ʽ����ÿһ��ڵ��ƽ��ֵ��
//��ʵ�ʴ���� 10 - 5 ���ڵĴ𰸿��Ա����ܡ�

///////////////����˼·��102�������Ĳ������һ�£�ע����������ת��
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
                d_sum += temp->val;  //�洢ÿ����ۺ�
                if (temp->left != nullptr) duilie.push(temp->left);
                if (temp->right != nullptr) duilie.push(temp->right);
            }
            res.push_back(d_sum / d_size);
        }
        return res;
    }
};