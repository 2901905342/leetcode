//数对(a, b) 由整数 a 和 b 组成，其数对距离定义为 a 和 b 的绝对差值。
//给你一个整数数组 nums 和一个整数 k ，数对由 nums[i] 和 nums[j] 组成且满足 0 <= i < j < nums.length 。
//返回 所有数对距离中 第 k 小的数对距离。

//方法一：排序 + 二分查找+双指针
//先将数组 nums 从小到大进行排序。因为第 kk 小的数对距离必然在区间[0, max(nums)−min(nums)] 内，令 left = 0，right = max(nums)−min(nums)，我们在区间[left, right] 上进行二分。
//对于当前搜索的距离 mid，计算所有距离小于等于mid 的数对数目 cnt，如果 cnt≥k （----大于等于这一步要思考很久），那么right = mid−1，否则 left = mid + 1。
//当 left > right 时，终止搜索，那么第 k 小的数对距离为left。
/*给定距离 mid，计算所有距离小于等于mid 的数对数目 cnt 可以使用双指针：初始左端点 i = 0，
我们从小到大枚举所有数对的右端点 j，移动左端点直到nums[j]−nums[i]≤mid，
那么右端点为 j 且距离小于等mid 的数对数目为 j−i，计算这些数目之和*/

#include "myhead.h"
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), left = 0, right = nums.back() - nums.front();
        while (left <= right) {
            int mid = (left + right) / 2;
            int cnt = 0;
            for (int i = 0, j = 0; j < n; j++) {
                while (nums[j] - nums[i] > mid) {
                    i++;
                }
                cnt += j - i;
            }

            if (cnt >= k) { //cnt==k时，可能是小于mid的有k个
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};

