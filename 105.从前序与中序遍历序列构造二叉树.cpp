﻿//给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。

/////思路：
//对于任意一颗树而言，前序遍历的形式总是
//[根节点, [左子树的前序遍历结果], [右子树的前序遍历结果]]
//即根节点总是前序遍历中的第一个节点。而中序遍历的形式总是
//[[左子树的中序遍历结果], 根节点, [右子树的中序遍历结果]]
//只要我们在中序遍历中定位到根节点，那么我们就可以分别知道左子树和右子树中的节点数目。
//由于同一颗子树的前序遍历和中序遍历的长度显然是相同的，因此我们就可以对应到前序遍历的结果中，对上述形式中的所有左右括号进行定位。
//这样以来，我们就知道了左子树的前序遍历和中序遍历结果，以及右子树的前序遍历和中序遍历结果，我们就可以递归地对构造出左子树和右子树，再将这两颗子树接到根节点的左右位置。


#include "myhead.h"

// * Definition for a binary tree node.*/
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
///自己写法，用数组存储左右子树的前序和中序遍历
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        int index = 0;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == preorder[0]) {
                index = i;
                break;
            }
        }
        vector<int>left_preorder;
        vector<int>right_preorder;
        vector<int>left_inorder;
        vector<int>right_inorder;
        for (int i = 1; i < preorder.size(); i++) {
            if (i <= index)    left_preorder.push_back(preorder[i]);
            else right_preorder.push_back(preorder[i]);

        }
        for (int i = 0; i < inorder.size(); i++) {
            if (i < index) left_inorder.push_back(inorder[i]);
            if (i > index) right_inorder.push_back(inorder[i]);
        }
        if (left_inorder.size()) root->left = buildTree(left_preorder, left_inorder);
        if (right_inorder.size()) root->right = buildTree(right_preorder, right_inorder);
        return root;

    }
};

///自己写法，优化

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root = new TreeNode(preorder[0]);
        int index = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();
        vector<int>left_preorder;
        vector<int>right_preorder;
        vector<int>left_inorder;
        vector<int>right_inorder;
        if (index >= 1) left_preorder.assign(preorder.begin() + 1, preorder.begin() + index + 1);
        right_preorder.assign(preorder.begin() + index + 1, preorder.end());
        left_inorder.assign(inorder.begin(), inorder.begin() + index);
        right_inorder.assign(inorder.begin() + index + 1, inorder.end());
        if (left_inorder.size()) root->left = buildTree(left_preorder, left_inorder);
        if (right_inorder.size()) root->right = buildTree(right_preorder, right_inorder);
        return root;

    }
};

////细节：
//在中序遍历中对根节点进行定位时，一种简单的方法是直接扫描整个中序遍历的结果并找出根节点，但这样做的时间复杂度较高。
//我们可以考虑使用哈希表来帮助我们快速地定位根节点。对于哈希映射中的每个键值对，键表示一个元素（节点的值），值表示其在中序遍历中的出现位置。
//在构造二叉树的过程之前，我们可以对中序遍历的列表进行一遍扫描，就可以构造出这个哈希映射。在此后构造二叉树的过程中，我们就只需要 O(1)O(1) 的时间对根节点进行定位了。

class Solution {
public:
    unordered_map<int, int> hash;
    vector<int> preorder, inorder;

    TreeNode* buildTree(vector<int>& _preorder, vector<int>& _inorder) {
        preorder = _preorder, inorder = _inorder;
        for (int i = 0; i < inorder.size(); ++i) hash[inorder[i]] = i;
        return dfs(0, preorder.size() - 1, 0, inorder.size() - 1);
    }

    TreeNode* dfs(int pl, int pr, int il, int ir) {
        if (pl > pr) return nullptr;
        auto root = new TreeNode(preorder[pl]);
        int k = hash[root->val];
        auto left = dfs(pl + 1, pl + k - il, il, k - 1);
        auto right = dfs(pl + k - il + 1, pr, k + 1, ir);
        root->left = left, root->right = right;
        return root;
    }
};