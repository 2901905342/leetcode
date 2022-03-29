//给你一个下标从 0 开始的整数数组 nums ，该数组的大小为 n ，
//请你计算 nums[j] - nums[i] 能求得的 最大差值 ，其中 0 <= i < j < n 且 nums[i] < nums[j] 。
//返回 最大差值 。如果不存在满足要求的 i 和 j ，返回 - 1 。


#include "myhead.h"
///////思路1：暴力解法
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int res = 0;
        int min_num = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            min_num = min(nums[i], min_num);
            for (int j = i + 1; j < nums.size(); j++) {
                res = max(res, nums[j] - nums[i]);
            }
        }
        return res > 0 ? res : -1;
    }

};
//////思路2：前缀最小值
//当我们固定 j时，选择的下标 i一定是满足 0≤i < j 并且 nums[i] 最小的那个 i。
// 因此我们可以使用循环对 j 进行遍历，同时维护nums[0..j−1] 的前缀最小值，记为min_num。这样一来：
// 如果nums[i] > premin，那么就用nums[i]−min_num 对答案进行更新；
// 否则，用 nums[i] 来更新前缀最小值min_num。
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int res = 0;
        int min_num = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > min_num) res = max(res, nums[i] - min_num);
            else min_num = nums[i];
        }
        return res > 0 ? res : -1;
    }

};






  