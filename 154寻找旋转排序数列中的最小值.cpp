//已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。
//例如，原数组 nums = [0, 1, 4, 4, 5, 6, 7] 在变化后可能得到：
//若旋转 4 次，则可以得到[4, 5, 6, 7, 0, 1, 4]
//若旋转 7 次，则可以得到[0, 1, 4, 4, 5, 6, 7]
//注意，数组[a[0], a[1], a[2], ..., a[n - 1]] 旋转一次 的结果为数组[a[n - 1], a[0], a[1], a[2], ..., a[n - 2]] 。
//给你一个可能存在 重复 元素值的数组 nums ，
//它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素 。

#include "myhead.h"

/// <summary>
/// /////////思路1：直接排序，输出第一个就是了时间复杂度o（nlogn)
/// </summary>
class Solution {
public:
    int findMin(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[0];
    }
};


///////进阶： 暴力法，时间O(n)
class Solution {
public:
    int findMin(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) return nums[i];  //返回临界点
        }
        return nums[0];  //没有临界点说明整个数组是升序排列
    }
};


///进阶:二分查找结合暴力法，时间 0(logn)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            }
            else if (nums[mid] < nums[right]) {
                right = mid;
            }
            else  right--;
        }
        return nums[left];
    }
};