//给你一个整数数组 nums ，请你找出 nums 子集 按位或 可能得到的 最大值 ，并返回按位或能得到最大值的 不同非空子集的数目 。
//如果数组 a 可以由数组 b 删除一些元素（或不删除）得到，则认为数组 a 是数组 b 的一个 子集 。
//如果选中的元素下标位置不一样，则认为两个子集 不同 。
//对数组 a 执行 按位或 ，结果等于 a[0] OR a[1] OR ... OR a[a.length - 1]（下标从 0 开始）。

////思路：DFS，但要注意到位或是不可逆运算，需要特殊写法，注意到位或只会越操作数字越大，所以最大值一定是所有元素的位或
// 
//事实上，我们可以在「枚举子集」的同时「计算相应得分」，设计 void dfs(int u, int val) 的 DFS 函数来实现「爆搜」，
//其中 uu为当前的搜索到 nums 的第几位，valval 为当前的得分情况。
//对于任意一位 x 而言，都有「选」和「不选」两种选择，分别对应了 dfs(u + 1, val | nums[x]) 和 dfs(u + 1, val) 两条搜索路径，
//在搜索所有状态过程中，使用全局变量 max 和 ans 来记录「最大得分」以及「取得最大得分的状态数量」。
//该做法将多条「具有相同前缀」的搜索路径的公共计算部分进行了复用，从而将算法复杂度下降为 O(2 ^ n)。

#include "myhead.h"
class Solution {
public:
    void dfs(vector<int>& nums, int& res, int& maxor, int pos, int record) {
        if (pos == nums.size()) {
            if (record == maxor) res++;
            return;
        }
        dfs(nums, res, maxor, pos + 1, record);
        dfs(nums, res, maxor, pos + 1, record | nums[pos]);
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxor = 0;
        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            maxor |= nums[i];
        }
        dfs(nums, res, maxor, 0, 0);
        return res;
    }
};