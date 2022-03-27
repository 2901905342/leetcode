//你和一群强盗准备打劫银行。给你一个下标从 0 开始的整数数组 security ，其中 security[i] 是第 i 天执勤警卫的数量。日子从 0 开始编号。同时给你一个整数 time 。
//如果第 i 天满足以下所有条件，我们称它为一个适合打劫银行的日子：
//第 i 天前和后都分别至少有 time 天。
//第 i 天前连续 time 天警卫数目都是非递增的。
//第 i 天后连续 time 天警卫数目都是非递减的。
//更正式的，第 i 天是一个合适打劫银行的日子当且仅当：security[i - time] >= security[i - time + 1] >= ... >= security[i] <= ... <= security[i + time - 1] <= security[i + time].
//请你返回一个数组，包含 所有 适合打劫银行的日子（下标从 0 开始）。返回的日子可以 任意 顺序排列。

/////思路：遍历整个数组，分别用两个单调栈递增以及递减的数列，
//当递减栈的长度大于等于time+1时，说明当前下标i是可能的潜在日子，用hash表存储i
//当递增栈的长度达到time+1时，且i-time在hash表中是，i-time就是好日子
//

#include "myhead.h"
class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        unordered_set<int> record;
        vector<int> res;
        int n = security.size();
        if (n < 2 * time + 1) return res;
        vector<int> temp;
        vector<int> temp2;
        for (int i = 0; i < n; i++) {
            if (!temp.empty() && temp.back() < security[i]) temp.clear();
            temp.push_back(security[i]);
            if (temp.size() >= time + 1) {
                record.insert(i);
            }
            if (!temp2.empty() && temp2.back() > security[i]) temp2.clear();
            temp2.push_back(security[i]);
            if (temp2.size() >= time + 1 && record.count(i - time)) {
                res.push_back(i - time);
            }
        }

        return res;
    }
};

/// <summary>
/// ///改进虚拟栈，不用真存储数据
/// </summary>
class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        unordered_set<int> record;
        vector<int> res;
        int n = security.size();
        if (n < 2 * time + 1) return res;
        int count_add = 0;
        int count_sub = 0;
        int max = security[0];
        int min = security[0];
        for (int i = 0; i < n; i++) {
            count_add = security[i] >= max ? count_add + 1 : 1;
            count_sub = security[i] <= min ? count_sub + 1 : 1;
            max = security[i];
            min = security[i];
            if (count_sub >= time + 1) record.insert(i);
            if (count_add >= time + 1 && record.count(i - time)) res.push_back(i - time);
        }
        return res;
    }
};