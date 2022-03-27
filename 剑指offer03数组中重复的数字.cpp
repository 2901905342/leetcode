//找出数组中重复的数字。
//在一个长度为 n 的数组 nums 里的所有数字都在 0～n - 1 的范围内。
//数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。

///////思路：  毫无疑问用hash表
////可以使用set容器做hash表
///进一步优化：由于长度为 n 的数组 nums 里的所有数字都在 0～n - 1 的范围内，可用数组做hash表，性能有所提升


#include "myhead.h"
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        unordered_set<int> hash;  //使用ununordered_set比使用set耗时要少很多
        for (int i = 0; i < nums.size(); i++) {
            if (hash.count(nums[i])) return nums[i];
            hash.insert(nums[i]);
        }
        return -1;
    }
};

//终优化： 此说明含义：数组元素的 索引 和 值 是 一对多 的关系。
//因此，可遍历数组并通过交换操作，使元素的 索引 与 值 一一对应（即 nums[i] = i）。
//因而，就能通过索引映射对应的值，起到与字典等价的作用。
//遍历中，第一次遇到数字 x 时，将其交换至索引 x 处；而当第二次遇到数字 x 时，一定有 nums[x] = x ，
//此时即可得到一组重复数字。
//算法流程：
//遍历数组 nums ，设索引初始值为 i = 0:
//若 nums[i] = i ： 说明此数字已在对应索引位置，无需交换，因此跳过；
//若 nums[nums[i]] = nums[i] ： 代表索引 nums[i] 处和索引 i 处的元素值都为 nums[i] ，即找到一组重复值，返回此值 nums[i] ；
//否则： 交换索引为 ii和 nums[i]的元素值，将此数字交换至对应索引位置。
//若遍历完毕尚未返回，则返回 - 1 。


class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] == i) {
                i++;
                continue;
            }
            if (nums[nums[i]] == nums[i])
                return nums[i];
            swap(nums[i], nums[nums[i]]);
        }
        return -1;
    }
};

