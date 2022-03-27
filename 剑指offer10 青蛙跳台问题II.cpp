//一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
//答案需要取模 1e9 + 7（1000000007），如计算初始结果为：1000000008，请返回 1。

///////////////思路  ：典型的斐波那契数列问题

#include "myhead.h"
class Solution {
public:
    int numWays(int n) {
        if (n && n < 3) return n;
        int MOD = 1000000007;
        int a = 1;
        int b = 2;
        int c = 1;
        while (n > 2) {
            c = (a + b) % MOD;
            a = b;
            b = c;
            n--;
        }
        return c;

    }
};