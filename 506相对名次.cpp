//给你一个长度为 n 的整数数组 score ，其中 score[i] 是第 i 位运动员在比赛中的得分。所有得分都 互不相同 。
//
//运动员将根据得分 决定名次 ，其中名次第 1 的运动员得分最高，名次第 2 的运动员得分第 2 高，依此类推。运动员的名次决定了他们的获奖情况：
//
//名次第 1 的运动员获金牌 "Gold Medal" 。
//名次第 2 的运动员获银牌 "Silver Medal" 。
//名次第 3 的运动员获铜牌 "Bronze Medal" 。
//从名次第 4 到第 n 的运动员，只能获得他们的名次编号（即，名次第 x 的运动员获得编号 "x"）。
//使用长度为 n 的数组 answer 返回获奖，其中 answer[i] 是第 i 位运动员的获奖情况。



#include "myhead.h"


//方法一  排序
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int> order;
        for (int i = 0; i < nums.size(); i++)
            order.push_back(i);
        sort(order.begin(), order.end(), [&nums](const int& a, const int& b) {return nums[a] > nums[b]; });
        vector<string> res(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            switch (i)
            {
            case 0:res[order[i]] = "Gold Medal"; break;
            case 1:res[order[i]] = "Silver Medal"; break;
            case 2:res[order[i]] = "Bronze Medal"; break;
            default:res[order[i]] = to_string(i + 1); break;
            }
        }
        return res;
    }
};

//方法二  hash表