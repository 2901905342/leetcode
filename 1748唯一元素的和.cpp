//给你一个整数数组 nums 。
//数组中唯一元素是那些只出现 恰好一次 的元素。
//请你返回 nums 中唯一元素的 和 。
//1 <= nums.length <= 100
//1 <= nums[i] <= 100
/////思路：哈希表，主要注意统计元素出现的次数
/// 注意官方的写法

#include "myhead.h"
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> hash_table(101, 0);  //用数组作哈希表
        for (int num : nums) {
            hash_table[num]++;
        }
        int res = 0;
        for (int num : nums) {
            if (hash_table[num] == 1) res += num;
        }
        return res;
    }
};

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int num : nums) {
            ++cnt[num]; //这里的写法很有意思
        }
        int ans = 0;
        for (auto& it : cnt) {
            if (it.second == 1) {
                ans += it.first; //注意这里的写法
            }
        }
        return ans;
    }
};

