//、、、给定一个二叉树，检查它是否是镜像对称的


/////思路//////////////
//正是因为要遍历两棵树而且要比较内侧和外侧节点，
//所以准确的来说是一个树的遍历顺序是左右中，一个树的遍历顺序是右左中。

//要比较两个节点数值相不相同，首先要把两个节点为空的情况弄清楚！
//否则后面比较数值的时候就会操作空指针了。
//节点为空的情况有：（注意我们比较的其实不是左孩子和右孩子，所以如下我称之为左节点右节点）
//左节点为空，右节点不为空，不对称，return false
//左不为空，右为空，不对称 return false
//左右都为空，对称，返回true
//此时已经排除掉了节点为空的情况，那么剩下的就是左右节点不为空：
//左右都不为空，比较节点数值，不相同就return false
//此时左右节点不为空，且数值也不相同的情况我们也处理了。

//
//进入单层递归的逻辑，单层递归的逻辑就是处理 左右节点都不为空，且数值相同的情况。
//比较二叉树外侧是否对称：传入的是左节点的左孩子，右节点的右孩子。
//比较内测是否对称，传入左节点的右孩子，右节点的左孩子。
//如果左右都对称就返回true ，有一侧不对称就返回false 。

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