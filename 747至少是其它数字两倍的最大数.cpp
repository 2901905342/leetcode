//给你一个整数数组 nums ，其中总是存在 唯一的 一个最大整数 。
//请你找出数组中的最大元素并检查它是否 至少是数组中每个其他数字的两倍 。
//如果是，则返回 最大元素的下标 ，否则返回 - 1 。
#include "myhead.h"

////////////////////////初版  用hash表来记录最大值的位置，运行时间8ms
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.size() == 1)  return 0;
        unordered_map<int, int> hash;
        int temp = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (temp < nums[i]) {
                hash[nums[i]] = i;
                temp = nums[i];
            }
        }
        sort(nums.begin(), nums.end());
        int num2 = 2 * nums[nums.size() - 2];
        if (temp < num2) return -1;
        else  return hash[temp];
    }
};

/// <summary>
/// //////////////////再版  根本不需要使用容器，能省下大量时间，运行0ms
/// </summary>
class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.size() == 1)  return 0;
        int temp = -1;
        int index = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (temp < nums[i]) {
                index = i;
                temp = nums[i];
            }
        }
        sort(nums.begin(), nums.end());
        int num2 = 2 * nums[nums.size() - 2];
        if (temp < num2) return -1;
        else  return index;
    }
};

/// <summary>
/// /////////////////官方写法，耗时应该是最短的
/// </summary>

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int m1 = -1, m2 = -1;
        int index = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > m1) {
                m2 = m1;
                m1 = nums[i];
                index = i;
            }
            else if (nums[i] > m2) {
                m2 = nums[i];
            }
        }
        return m1 >= m2 * 2 ? index : -1;
    }
};

