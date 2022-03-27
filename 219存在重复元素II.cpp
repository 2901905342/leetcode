//给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，满足 nums[i] == nums[j] 且 abs(i - j) <= k 。
//如果存在，返回 true ；否则，返回 false 。

////////////////思路   hash表
//当遍历到下标 i 时，如果在下标 i 之前存在与ums[i] 相等的元素，应该在这些元素中寻找最大的下标 j，判断 i−j≤k 是否成立。
//可以使用哈希表记录每个元素的最大下标。从左到右遍历数组nums，当遍历到下标 i 时，进行如下操作：
//如果哈希表中已经存在和nums[i] 相等的元素且该元素在哈希表中记录的下标 jj满足 i−j≤k，返回true；
//将 nums[i] 和下标 i 存入哈希表，此时 i 是nums[i] 的最大下标。
//上述两步操作的顺序不能改变，因为当遍历到下标 i 时，只能在下标 i 之前的元素中寻找与当前元素相等的元素及该元素的最大下标。
//当遍历结束时，如果没有遇到两个相等元素的下标差的绝对值不超过 k，返回 false。

#include "myhead.h"
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hash_table;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (hash_table.count(num) && i - hash_table[num] <= k) {
                //  关于此处的想法：当hash_table中不存在num元素时，第一个条件判断为假此时将不再判断第二个语句
                //当hash_table存在num元素时，第一个条件为真，才会继续判断第二个条件
                return true;
            }
            hash_table[num] = i;
        }
        return false;
    }
};