//你需要采用前序遍历的方式，将一个二叉树转换成一个由括号和整数组成的字符串。
//
//空节点则用一对空括号 "()" 表示。而且你需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。
//
//题目的意思是子节点需要用()来包裹。
//举例来说，二叉树[root, left, right]，则转换为root(left)(right)。
//如果只有left为空节点，则输出root()(right)
//；如果只有right为空节点则可以忽略右节点的()，输出为root(left)。

///////思路：递归


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