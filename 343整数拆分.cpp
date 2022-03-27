//给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。
//返回 你可以获得的最大乘积 。


/////思路 ：能拆分三就拆分三，不能就拆分二
//最优： 3 。把数字 n 可能拆为多个因子 3 ，余数可能为 0, 1, 2 三种情况。
//次优： 2 。若余数为 2；则保留，不再拆 。
//最差： 1 。若余数为 1 ；则应把一份 3 + 1 替换为2 + 2，因为 2 * 2 > 3 * 1;


#include "myhead.h"
class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) return n - 1; //对边界情况进行讨论
        int a = n / 3;
        int b = n % 3;
        if (b == 0) return pow(3, a);
        else if (b == 1) return 4 * pow(3, a - 1);
        else return 2 * pow(3, a);
    }
};