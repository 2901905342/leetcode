//输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数在数组的前半部分，所有偶数在数组的后半部分。
///思路：双指针
#include "myhead.h"
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            while (nums[left] % 2 && left < right) {
                left++;
            }
            while (nums[right] % 2 == 0 && left < right) {
                right--;
            }
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
        return nums;
    }
};