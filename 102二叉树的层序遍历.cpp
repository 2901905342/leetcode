//����������ĸ��ڵ� root ��������ڵ�ֵ�� ������� �� �������أ������ҷ������нڵ㣩��

//////˼·�����ö��и������BFS(������ȱ�����

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
                // ����һ��Ҫʹ�ù̶���Сd_size����Ҫʹ��duilie.size()����Ϊduilie.size�ǲ��ϱ仯��
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