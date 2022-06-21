//当 k 个日程安排有一些时间上的交叉时（例如 k 个日程安排都在同一时间内），就会产生 k 次预订。
//给你一些日程安排[start, end) ，请你在每个日程安排添加后，返回一个整数 k ，表示所有先前日程安排会产生的最大 k 次预订。
//实现一个 MyCalendarThree 类来存放你的日程安排，你可以一直添加新的日程安排。
//MyCalendarThree() 初始化对象。
//int book(int start, int end) 返回一个整数 k ，表示日历中存在的 k 次预订的最大值。

//方法一：差分数组
//我们可以采用同样的思路即可。利用差分数组的思想，每当我们预定一个新的日程安排[start, end)，
//在 start 计数cnt[start] 加 1，表示从start 预定的数目加 1；
//从 end 计数cnt[end] 减 1，表示从 end 开始预定的数目减 1。
//此时以起点 x开始的预定的数目x= ∑（y≤x)​ cnt[y]，我们对计数进行累加依次求出最大的预定数目即可。
//由于本题中 start, end 数量较大，我们利用 Map 计数即可。

#include "myhead.h"
class MyCalendarThree {
public:
    map<int, int>cnt;
    MyCalendarThree() {

    }

    int book(int start, int end) {
        int res = 0;
        int temp = 0;
        cnt[start]++;
        cnt[end]--;
        for (auto it = cnt.begin(); it != cnt.end(); it++) {
            temp += it->second;
            res = max(temp, res);
        }
        return res;
    }
};


////方法二：线段树  ，还不会