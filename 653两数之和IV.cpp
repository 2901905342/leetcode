//����һ������������ root ��һ��Ŀ���� k����� BST �д�������Ԫ�������ǵĺ͵��ڸ�����Ŀ�������򷵻� true��
//�����������Binary Search Tree�������֣���������������������������������һ�ÿ����������Ǿ����������ʵĶ������� 
//���������������գ��������������н���ֵ��С�����ĸ�����ֵ�� 
//���������������գ��������������н���ֵ���������ĸ�����ֵ��
//������������Ҳ�ֱ�Ϊ������������

/////////˼·1���������+hash��ʱ�临�Ӷ�O(2n)

#include "myhead.h"
/* Definition for a binary tree node.*/
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
    void qianxu(TreeNode* node, vector<int>& temp) {
        if (node->left != nullptr) qianxu(node->left, temp);
        temp.push_back(node->val);
        if (node->right != nullptr) qianxu(node->right, temp);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> record;
        unordered_set<int> hash_table;
        qianxu(root, record);
        for (auto x : record) {
            if (hash_table.count(k - x)) return true;
            hash_table.insert(x);
        }
        return false;

    }
};

/////////////�ٷ��������������� + ��ϣ��ʱ�临�Ӷ�O(n)

class Solution {
public:
    unordered_set<int> hashTable;

    bool findTarget(TreeNode* root, int k) {
        if (root == nullptr) {
            return false;
        }
        if (hashTable.count(k - root->val)) {
            return true;
        }
        hashTable.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};

