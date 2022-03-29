//����������һ����������������Ƿ��Ǿ���ԳƵ�


/////˼·//////////////
//������ΪҪ��������������Ҫ�Ƚ��ڲ�����ڵ㣬
//����׼ȷ����˵��һ�����ı���˳���������У�һ�����ı���˳���������С�

//Ҫ�Ƚ������ڵ���ֵ�಻��ͬ������Ҫ�������ڵ�Ϊ�յ����Ū�����
//�������Ƚ���ֵ��ʱ��ͻ������ָ���ˡ�
//�ڵ�Ϊ�յ�����У���ע�����ǱȽϵ���ʵ�������Ӻ��Һ��ӣ����������ҳ�֮Ϊ��ڵ��ҽڵ㣩
//��ڵ�Ϊ�գ��ҽڵ㲻Ϊ�գ����Գƣ�return false
//��Ϊ�գ���Ϊ�գ����Գ� return false
//���Ҷ�Ϊ�գ��Գƣ�����true
//��ʱ�Ѿ��ų����˽ڵ�Ϊ�յ��������ôʣ�µľ������ҽڵ㲻Ϊ�գ�
//���Ҷ���Ϊ�գ��ȽϽڵ���ֵ������ͬ��return false
//��ʱ���ҽڵ㲻Ϊ�գ�����ֵҲ����ͬ���������Ҳ�����ˡ�

//
//���뵥��ݹ���߼�������ݹ���߼����Ǵ��� ���ҽڵ㶼��Ϊ�գ�����ֵ��ͬ�������
//�Ƚ϶���������Ƿ�Գƣ����������ڵ�����ӣ��ҽڵ���Һ��ӡ�
//�Ƚ��ڲ��Ƿ�Գƣ�������ڵ���Һ��ӣ��ҽڵ�����ӡ�
//������Ҷ��Գƾͷ���true ����һ�಻�Գƾͷ���false ��

#include "myhead.h"


// Definition for a binary tree node.
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
    bool compare(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) return true;
        else if (left != nullptr && right == nullptr) return false;
        else if (left == nullptr && right != nullptr) return false;
        else if (left->val != right->val) return false;
        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);
        bool bothside = outside & inside;
        return bothside;
    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return  compare(root->left, root->right);
    }
};