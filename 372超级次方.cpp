//你的任务是计算 ab 对 1337 取模，a 是一个正整数，
//b 是一个非常大的正整数且会以数组形式给出。



/////////////解题思路////////////////////////
//(a*b)%MOD=((a%MOD)*(b%MOD)%MOD)
//且power(a,123)=power(a,100)*power(a,20)*power(a,3)

  //////快速幂运算////////////
//我们换一个角度来引入非递归的快速幂。还是7的10次方，但这次，我们把10写成二进制的形式，也就是 7幂(1010)2 。
//现在我们要计算 7幂(1010)2 ，可以怎么做？我们很自然地想到可以把它拆分为  7幂(1000)2  *   7幂(10)2
//最初ans为1，然后我们一位一位算：
//1010的最后一位是0，所以a ^ 1这一位不要。然后1010变为101，a变为a ^ 2。（这里a^2表示a的平方，是伪代码，而不是真代码）
//101的最后一位是1，所以a ^ 2这一位是需要的，乘入ans。101变为10，a再自乘。（真代码情况下a^2表示a与2异或）
//10的最后一位是0，跳过，右移，自乘。
//然后1的最后一位是1，ans再乘上a ^ 8。循环结束，返回结果。


#include "myhead.h"
class Solution {
public:
    int const MOD = 1337;
    int fastpow(int x, int n) {
        int res = 1;
        while (n > 0) {
            if (n & 1) {//如果n是奇数
                res = (res * x) % MOD;
            }
            n >>= 1;
            x = (x * x) % MOD;
        }
        return res;
    }
    int superPow(int a, vector<int>& b) {
        if (a == 1) return a;
        a = a % MOD;
        int ans = 1;
        int k = 1;
        for (int j = b.size() - 1; j >= 0; j--) {
            int y = b[j];
            ans = (ans * fastpow(a, y)) % MOD;
            a = fastpow(a, 10);
        }
        return ans;

    }
};