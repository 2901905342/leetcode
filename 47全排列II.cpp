//给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。


//思路：DFS
//要解决重复问题，我们只要设定一个规则，保证在填第 idx 个数的时候重复数字只会被填入一次即可。
//而在本题解中，我们选择对原数组排序，保证相同的数字都相邻，然后每次填入的数一定是这个数所在重复数集合中「从左往右第一个未被填过的数字」
//这个判断条件保证了对于重复数的集合，一定是从左往右逐个填入的。
//假设我们有 33 个重复数排完序后相邻，那么我们一定保证每次都是拿从左往右第一个未被填过的数字，
//即整个数组的状态其实是保证了[未填入，未填入，未填入] 到[填入，未填入，未填入]，再到[填入，填入，未填入]，最后到[填入，填入，填入] 的过程的，
//因此可以达到去重的目标。



#include "myhead.h"
class Solution {
public:
    void dfs(vector<int>& path, vector<vector<int>>& res, vector<int>& nums, vector<int> hash_table) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (hash_table[i])  continue; //避免和自身重复
            if (i > 0 && (nums[i] == nums[i - 1]) && !hash_table[i - 1]) continue; //避免重复数字重复被填入
            path.push_back(nums[i]);
            hash_table[i] = 1;
            dfs(path, res, nums, hash_table);
            path.pop_back();
            hash_table[i] = 0;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> res;
        vector<int> hash_table(nums.size());  //存放已经使用过的元素的下标
        sort(nums.begin(), nums.end());   //对原数组排序
        dfs(path, res, nums, hash_table);
        return res;
    }
};