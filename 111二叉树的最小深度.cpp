//����һ�����������ҳ�����С��ȡ�
//��С����ǴӸ��ڵ㵽���Ҷ�ӽڵ�����·���ϵĽڵ�������
//˵����Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣

///˼·��������ȱ������ҵ���һ��Ҷ�ӽڵ�(��Ȼ�����Ҷ�ӽڵ㣩�ͷ���

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