//����һ�������ظ����ֵ����� nums �������� ���п��ܵ�ȫ���� ������� ������˳�� ���ش𰸡�
////˼·����DFS���������鲻�����ظ����֣�����ֱ��ʹ�ù�ϣ���¼�Ѿ�ʹ�õ�����

#include "myhead.h"
class Solution {
public:
    void dfs(vector<int>& path, vector<vector<int>>& res, vector<int>& nums, unordered_set<int>& hash_table) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (auto num : nums) {
            if (hash_table.count(num)) continue;
            path.push_back(num);
            hash_table.insert(num);
            dfs(path, res, nums, hash_table);
            path.pop_back();
            hash_table.erase(num);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> res;
        unordered_set<int> hash_table;
        dfs(path, res, nums, hash_table);
        return res;
    }
};