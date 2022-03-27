//给定一个 n 叉树的根节点 root ，返回 其节点值的 后序遍历 。
//n 叉树 在输入中按层序遍历进行序列化表示，
//每组子节点由空值 null 分隔（请参见示例）。


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
            for (int i = 0; i < temp->children.size(); i++) {
                dfs(res, temp->children[i]);
            }
            res.push_back(temp->val);
        }
    }
    vector<int> postorder(Node* root) {
        vector<int> res;
        dfs(res, root);
        return res;
    }
};