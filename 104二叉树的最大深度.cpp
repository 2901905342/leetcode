//����һ�����������ҳ��������ȡ�
//
//�����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����
//
//˵�� : Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣

//���ϲ���������ȱ�������

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
/// ///��ȻҲ����ʹ��BFS
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