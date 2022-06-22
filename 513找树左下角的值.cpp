//给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。
//假设二叉树中至少有一个节点。

////思路：BFS，层序遍历，找到最后一层最左边节点即可

#include "myhead.h"
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
    int findBottomLeftValue(TreeNode* root) {
        vector<vector<int>>record;
        queue<TreeNode*>duilie;
        if (root != nullptr) duilie.push(root);
        while (!duilie.empty()) {
            int d_size = duilie.size();
            vector<int>temp;
            for (int i = 0; i < d_size; i++) {
                auto x = duilie.front();
                duilie.pop();
                temp.push_back(x->val);
                if (x->left != nullptr) duilie.push(x->left);
                if (x->right != nullptr) duilie.push(x->right);
            }
            record.push_back(temp);
        }
        int n = record.size();
        return record[n - 1][0];

    }
};

///官方BFS写法，空间复杂度更低
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int ret;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            if (p->right) {
                q.push(p->right);
            }
            if (p->left) {
                q.push(p->left);
            }
            ret = p->val;
        }
        return ret;
    }
};


//深度优先搜索
//height 记录遍历到的节点的高度，curVal 记录高度在 curHeight 的最左节点的值。
//在深度优先搜索时，我们先搜索当前节点的左子节点，再搜索当前节点的右子节点，
//然后判断当前节点的高度 height 是否大于curHeight，
//如果是，那么将curVal 设置为当前结点的值，curHeight 设置为 height。

class Solution {
public:
    void dfs(TreeNode* root, int height, int& curVal, int& curHeight) {
        if (root == nullptr) {
            return;
        }
        height++;
        dfs(root->left, height, curVal, curHeight);
        dfs(root->right, height, curVal, curHeight);
        if (height > curHeight) {
            curHeight = height;
            curVal = root->val;
        }
    }

    int findBottomLeftValue(TreeNode* root) {
        int curVal, curHeight = 0;
        dfs(root, 0, curVal, curHeight);
        return curVal;
    }
};

