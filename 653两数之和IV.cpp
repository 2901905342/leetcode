//给定一个二叉搜索树 root 和一个目标结果 k，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。
//二叉查找树（Binary Search Tree），（又：二叉搜索树，二叉排序树）它或者是一棵空树，或者是具有下列性质的二叉树： 
//若它的左子树不空，则左子树上所有结点的值均小于它的根结点的值； 
//若它的右子树不空，则右子树上所有结点的值均大于它的根结点的值；
//它的左、右子树也分别为二叉排序树。

/////////思路1；中序遍历+hash表，时间复杂度O(2n)

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

/////////////官方解答：深度优先搜索 + 哈希表，时间复杂度O(n)

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

