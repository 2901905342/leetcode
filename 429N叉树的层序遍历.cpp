//给定一个 N 叉树，返回其节点值的层序遍历。（即从左到右，逐层遍历）。
//树的序列化输入是用层序遍历，每组子节点都由 null 值分隔（参见示例）。

////值得注意的是N叉树的节点含有多个子节点，在题目构建的数据结构中
///这些子节点统一放在一个向量容器中
////思路：还是典型的广度优先搜索

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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        queue<Node* > duilie;  //存放节点的队列
        if (root != nullptr) duilie.push(root);
        while (!duilie.empty()) {
            int d_size = duilie.size();
            vector<int> vec;
            for (int i = 0; i < d_size; i++) {
                Node* temp = duilie.front();
                duilie.pop();
                vec.push_back(temp->val);
                for (auto child : temp->children) { //遍历当前节点的所有子节点
                    if (child != nullptr) {
                        duilie.push(child);      //将所有非空节点放入队列中
                    }
                }
            }
            res.push_back(vec);
        }
        return res;
    }
};