//给定一个整数数组 nums 和一个整数目标值 target，
//请你在该数组中找出 和为目标值 target 的那 两个 整数，并返回它们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
//你可以按任意顺序返回答案。

////////////////////////思路//////////////////////////////////
/////////思路1 ： 双指针（快慢指针），确定时间复杂度较高
/////////思路2：使用hash表 ，注意一边添加数据一边进行判断，代码只展示hash表的写法

#include "myhead.h"
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            if (hash.count(target - nums[i])) {
                res.push_back(hash[target - nums[i]]);
                res.push_back(i);
                return res;
            }
            hash[nums[i]] = i;
        }
        return res;  //  虽然这一行有些多余，但不加上leetcode上会报错
    }
};

