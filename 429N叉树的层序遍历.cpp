//����һ�� N ������������ڵ�ֵ�Ĳ�����������������ң�����������
//�������л��������ò��������ÿ���ӽڵ㶼�� null ֵ�ָ����μ�ʾ������

////ֵ��ע�����N�����Ľڵ㺬�ж���ӽڵ㣬����Ŀ���������ݽṹ��
///��Щ�ӽڵ�ͳһ����һ������������
////˼·�����ǵ��͵Ĺ����������

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
        queue<Node* > duilie;  //��Žڵ�Ķ���
        if (root != nullptr) duilie.push(root);
        while (!duilie.empty()) {
            int d_size = duilie.size();
            vector<int> vec;
            for (int i = 0; i < d_size; i++) {
                Node* temp = duilie.front();
                duilie.pop();
                vec.push_back(temp->val);
                for (auto child : temp->children) { //������ǰ�ڵ�������ӽڵ�
                    if (child != nullptr) {
                        duilie.push(child);      //�����зǿսڵ���������
                    }
                }
            }
            res.push_back(vec);
        }
        return res;
    }
};