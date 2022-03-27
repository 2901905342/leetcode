//给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
////思路：用DFS，由于数组不存在重复数字，可以直接使用哈希表记录已经使用的数字

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