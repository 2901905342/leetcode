//����Ҫ����ǰ������ķ�ʽ����һ��������ת����һ�������ź�������ɵ��ַ�����
//
//�սڵ�����һ�Կ����� "()" ��ʾ����������Ҫʡ�����в�Ӱ���ַ�����ԭʼ������֮���һ��һӳ���ϵ�Ŀ����Ŷԡ�
//
//��Ŀ����˼���ӽڵ���Ҫ��()��������
//������˵��������[root, left, right]����ת��Ϊroot(left)(right)��
//���ֻ��leftΪ�սڵ㣬�����root()(right)
//�����ֻ��rightΪ�սڵ�����Ժ����ҽڵ��()�����Ϊroot(left)��

///////˼·���ݹ�


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
    string tree2str(TreeNode* root) {
        if (root == nullptr) return "";
        if (root->right != nullptr) {
            return to_string(root->val) + '(' + tree2str(root->left) + ')' + '(' + tree2str(root->right) + ')';
        }
        if (root->left != nullptr && root->right == nullptr) {
            return to_string(root->val) + '(' + tree2str(root->left) + ')';
        }
        else return to_string(root->val);
    }
};