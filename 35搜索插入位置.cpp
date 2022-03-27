//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
//如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
//请必须使用时间复杂度为 O(log n) 的算法。
//nums 为无重复元素的升序排列数组

///////////思路： 典型的二分查找，先处理边界条件
#include "myhead.h"
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        if (target > nums[right]) return right + 1;
        if (target < nums[0]) return 0;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) right = mid;
            else left = mid + 1;
        }
        return left;

    }
};