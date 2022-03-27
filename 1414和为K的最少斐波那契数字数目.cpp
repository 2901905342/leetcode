//给你数字 k ，请你返回和为 k 的斐波那契数字的最少数目，其中，每个斐波那契数字都可以被使用多次。
//斐波那契数字定义为：
//F1 = 1
//F2 = 1
//Fn = Fn - 1 + Fn - 2 ， 其中 n > 2 。
//数据保证对于给定的 k ，一定能找到可行解。

///思路：贪心  首先找到所有不超过 k 的斐波那契数字，然后每次贪心地选取不超过 kk的最大斐波那契数字，
//将 k 减去该斐波那契数字，重复该操作直到 k 变为 0，此时选取的斐波那契数字满足和为 k 且数目最少。
// 难的是证明过程，详见官方证明

#include "myhead.h"
class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> feibo(2, 1);  //构造函数，放入2个1
        int a = 1;
        int b = 1;
        while (a + b <= k) {
            int c = a + b;
            feibo.push_back(c);
            a = b;
            b = c;
        }//生成尾项不超过k的斐波那契数列
        int res = 0;
        for (int i = feibo.size() - 1; i >= 0 && k > 0; i--) {
            if (k >= feibo[i]) {
                k -= feibo[i];
                res++;
            }
        }
        return res;
    }
};
