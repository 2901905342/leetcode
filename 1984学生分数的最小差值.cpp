//给你一个 下标从 0 开始 的整数数组 nums ，其中 nums[i] 表示第 i 名学生的分数。另给你一个整数 k 。
//从数组中选出任意 k 名学生的分数，使这 k 个分数间 最高分 和 最低分 的 差值 达到 最小化 。
//返回可能的 最小差值 。

///////思路：先排序，取每一个下标为i的数与它之前的下标为i-k+1的数进行相减
//这道题容易误认为是求排序后任意两个相邻元素的最小差值记为tmin
//但实际不是的，例如k=3时，要取三个数，那tmin的值是小于等于题目所求数，
//因为第三元素会位于前两个元素为端点的区间外导致最高分或者最低分改变，题目所求数大于tmin的值

#include "myhead.h"
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        if (k == 1 || nums.size() == 1) return 0;
        sort(nums.begin(), nums.end());
        int res = 100000;
        for (int i = k - 1; i < nums.size(); i++) {
            // 关于起始位置，要满足i-k+1=0,故i=k-1
            res = min(res, nums[i] - nums[i - k + 1]);
        }
        return res;
    }
};