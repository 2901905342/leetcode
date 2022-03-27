//给定一个 n 叉树的根节点  root ，返回 其节点值的 前序遍历 。
//n 叉树 在输入中按层序遍历进行序列化表示，每组子节点由空值 null 分隔（请参见示例）。
////思路：  前序遍历： 中左右
//// 所谓  X序遍历  （中间节点  在前 中 后）；
////  简单的dfs

#include "myhead.h"
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    void dfs(vector<int>& res, Node* temp) {
        if (temp != nullptr) {
            res.push_back(temp->val);
            for (int i = 0; i < temp->children.size(); i++) {
                dfs(res, temp->children[i]);
            }
        }
    }
    vector<int> preorder(Node* root) {
        vector<int> res;
        dfs(res, root);
        return res;
    }
};