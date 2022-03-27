//给你一个长桌子，桌子上盘子和蜡烛排成一列。给你一个下标从 0 开始的字符串 s ，它只包含字符 '*' 和 '|' ，其中 '*' 表示一个 盘子 ，'|' 表示一支 蜡烛 。
//同时给你一个下标从 0 开始的二维整数数组 queries ，其中 queries[i] = [lefti, righti] 表示 子字符串 s[lefti...righti] （包含左右端点的字符）。
//对于每个查询，你需要找到 子字符串中 在 两支蜡烛之间 的盘子的 数目 。
//如果一个盘子在 子字符串中 左边和右边 都 至少有一支蜡烛，那么这个盘子满足在 两支蜡烛之间 。
//比方说，s = "||**||**|*" ，查询 [3, 8] ，表示的是子字符串 "*||**|" 。
//子字符串中在两支蜡烛之间的盘子数目为 2 ，子字符串中右边两个盘子在它们左边和右边 都 至少有一支蜡烛。
//请你返回一个整数数组 answer ，其中 answer[i] 是第 i 个查询的答案。


/////////思路：预处理+前缀和
//对于每一个询问，我们只需要找到给定区间内最左侧和最右侧的两个蜡烛，这样两个蜡烛之间的所有盘子都是符合条件的。
//对于寻找蜡烛，我们可以预处理区间内每个位置左侧的第一个蜡烛和右侧的第一个蜡烛。这样区间左端点 ​left_i
//右侧的第一个蜡烛即为区间最左侧的蜡烛，区间右端点 right_i​
//左侧的第一个蜡烛即为区间最右侧的蜡烛。
//对于计算盘子数量，我们可以计算盘子数量的前缀和preSum。
//假设找到的两蜡烛的位置分别为 x 和 y，那么两位置之间的盘子数量即为  preSum_y -  preSum _x
//这样我们就通过预处理，将寻找蜡烛和计算盘子数量两个操作的时间复杂度降至 O(1)，因此对于每个询问，时间复杂度为 O(1)。
//在实际代码中，可能某个位置的左侧或右侧是不存在蜡烛的，此时我们将对应数组的值记为 −1。
//当 x 为−1 或者 y 为 −1 或者 x≥y 时，不存在满足条件的盘子。同时注意到因为 xx位置是蜡烛，所以盘子数量也可以表示为
//preSum_y - preSum _x
//​这个写法可以防止 x 为 0 时数组越界。

#include "myhead.h"
class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<int> preSum(n);
        vector<int> left(n);
        for (int i = 0, sum = 0, l = -1; i < n; i++) {
            if (s[i] == '*') {
                sum++;
            }
            else {
                l = i;
            }
            preSum[i] = sum;
            left[i] = l;
        }
        
     
        vector<int> right(n);
        for (int i = n - 1, r = -1; i >= 0; i--) {
            if (s[i] == '|') {
                r = i;
            }
            right[i] = r;
        }
        vector<int> ans;
        for (auto& query : queries) {
            int x = right[query[0]], y = left[query[1]];
            ans.push_back(x == -1 || y == -1 || x >= y ? 0 : preSum[y] - preSum[x]);
        }
        return ans;
    }
};

