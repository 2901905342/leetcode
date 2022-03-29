//����һ�������������� ������ ���¶� ��
//
//һ������ �ڵ���¶� ���弴Ϊ���ýڵ��������Ľڵ�֮�ͺ��������ڵ�֮�͵� ��ľ���ֵ ��
// ���û���������Ļ����������Ľڵ�֮��Ϊ 0 ��û���������Ļ�Ҳ��һ����
// �ս����¶��� 0 ��
//
//������ ���¶Ⱦ��������нڵ���¶�֮�͡�

//�������⣬������Ҫ�ۼƶ����������н������������֮�������������֮�͵Ĳ�ľ���ֵ��
//��ˣ����ǿ���ʹ����������������ڱ���ÿ�����ʱ��
//�ۼ������������֮�������������֮�͵Ĳ�ľ���ֵ������������Ϊ���������Ľ��֮�͡�

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
