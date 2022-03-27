//����һ���������� ���ڵ� root��
//�����Լ�վ�������Ҳ࣬���մӶ������ײ���˳�򣬷��ش��Ҳ����ܿ����Ľڵ�ֵ��

////˼·  ͬ�������Ĳ������
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> duilie;
        if (root != nullptr) duilie.push(root);
        while (!duilie.empty()) {
            int d_size = duilie.size();
            vector<int> vec;
            for (int i = 0; i < d_size; i++) {
                TreeNode* temp = duilie.front();
                duilie.pop();
                vec.push_back(temp->val);
                if (temp->left != nullptr) duilie.push(temp->left);
                if (temp->right != nullptr) duilie.push(temp->right);
            }
            res.push_back(vec.back());
        }
        return res;
    }
};