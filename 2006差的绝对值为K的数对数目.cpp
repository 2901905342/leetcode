//给你一个整数数组 nums 和一个整数 k ，请你返回数对 (i, j) 的数目，满足 i < j 且  | nums[i] - nums[j]| == k 。
//	| x | 的值定义为：
//	如果 x >= 0 ，那么值为 x 。
//	如果 x < 0 ，那么值为  - x 。

//1 <= nums.length <= 200
//1 <= nums[i] <= 100
//1 <= k <= 99


#include "myhead.h"
///////////思路1：暴力解法，双重for循环，时间复杂度O（N^2)
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int res = 0;
        if (nums.size() == 1) return res;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (abs(nums[i] - nums[j]) == k) res++;
            }
        }
        return res;
    }
};

/// <summary>
/// /////////思路2：数组计数+一遍遍历
 ///if a-b>0 |a-b|=a-b=k  a=b+k;
///if  a-b<0  |a-b|=b-a=k  a=b-k;
/// 由于本题测试数据范围较小可以使用数组作为hash表计数
/// </summary>
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int res = 0;
        vector<int> hash(101, 0);
        if (nums.size() == 1) return res;
        for (int num : nums) {
            if (num + k <= 100 && hash[k + num]) res += hash[k + num];  
            //一定要注意条件num + k <= 100 保证索引不会越界
            if (num - k >= 1 && hash[num - k]) res += hash[num - k];
            //num - k >= 1也是同理
            hash[num]++;
        }
        return res;
    }
};

/////////////思路3：用数组计数需要考虑边界条件浪费精力，直接用map容器作为hash表（虽然在时间效率上低一些）

class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, int> hash;
        if (nums.size() == 1) return res;
        for (int num : nums) {
            if (hash[k + num]) res += hash[k + num];
            if (hash[num - k]) res += hash[num - k];
            hash[num]++;
        }
        return res;
    }
};