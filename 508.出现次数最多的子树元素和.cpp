//给你一个二叉树的根结点 root ，请返回出现次数最多的子树元素和。
//如果有多个元素出现的次数相同，返回所有出现次数最多的子树元素和（不限顺序）。
//一个结点的 「子树元素和」 定义为以该结点为根的二叉树上所有结点的元素之和（包括结点本身）。

//我们可以从根结点出发，深度优先搜索这棵二叉树。
//对于每棵子树，其子树元素和等于子树根结点的元素值，加上左子树的元素和，以及右子树的元素和。
//用哈希表统计每棵子树的元素和的出现次数，计算出现次数的最大值 maxCnt，最后将出现次数等于maxCnt 的所有元素和返回

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
    int recordfun(TreeNode* node, map<int, int>& record) {
        if (node == nullptr) return 0;
        int val = node->val + recordfun(node->left, record) + recordfun(node->right, record);
        record[val]++;
        return val;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        map<int, int>hash;
        vector<int>res;
        int temp = recordfun(root, hash);
        int index = hash.begin()->first;
        int maxnum = hash.begin()->second;
        for (auto it = hash.begin(); it != hash.end(); it++) {
            if (it->second == maxnum) res.push_back(it->first);
            if (it->second > maxnum) {
                maxnum = it->second;
                res.clear();
                res.push_back(it->first);
            }
        }
        return res;
    }
};

///官方写法：更为巧妙，

class Solution {
    unordered_map<int, int> cnt;
    int maxCnt = 0;

    int dfs(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int sum = node->val + dfs(node->left) + dfs(node->right);
        maxCnt = max(maxCnt, ++cnt[sum]);
        return sum;
    }

public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int> ans;
        for (auto it = cnt.begin();it!=cnt.end();it++) {
            if (it->second == maxCnt) {
                ans.emplace_back(it->first);
            }
        }
        return ans;
    }
};

