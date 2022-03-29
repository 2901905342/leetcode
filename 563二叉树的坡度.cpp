//给定一个二叉树，计算 整个树 的坡度 。
//
//一个树的 节点的坡度 定义即为，该节点左子树的节点之和和右子树节点之和的 差的绝对值 。
// 如果没有左子树的话，左子树的节点之和为 0 ；没有右子树的话也是一样。
// 空结点的坡度是 0 。
//
//整个树 的坡度就是其所有节点的坡度之和。

//根据题意，我们需要累计二叉树中所有结点的左子树结点之和与右子树结点之和的差的绝对值。
//因此，我们可以使用深度优先搜索，在遍历每个结点时，
//累加其左子树结点之和与右子树结点之和的差的绝对值，并返回以其为根结点的树的结点之和。

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
    int ans = 0;

    int findTilt(TreeNode* root) {
        dfs(root);
        return ans;
    }

    int dfs(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int sumLeft = dfs(node->left);
        int sumRight = dfs(node->right);
        ans += abs(sumLeft - sumRight);
        return sumLeft + sumRight + node->val;
    }
};
