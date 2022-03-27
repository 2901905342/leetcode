//给你一个整数 n ，请你返回所有 0 到 1 之间（不包括 0 和 1）满足分母小于等于  n 的 最简 分数 。
//分数可以以 任意 顺序返回。

/////思路：此题关键在于最简分数，原本我以为只要分母不能被分子整除就行，但其实不对，
// 例如“4/6”就不是最简分数，它可化简为“2/3”
////保证是最简分数，需要分子，分母的最大公约数（greatest common divisor，gcd）为1；
//一般采用辗转相除法：两数相除，取余数重复进行相除，直到余数为0时，前一个除数即为最大公约数。

#include "myhead.h"
class Solution {
public:
    /////////gcd函数的写法
    int gcd(int a, int b) {
        int r;
        while (b) {
            r = a % b;
            a = b;
            b = r;
        }
        return a;
    }
    vector<string> simplifiedFractions(int n) {
        vector<string> res;
        if (n == 1) return res;
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                if (gcd(j, i) == 1) {
                    string temp = to_string(i) + "/" + to_string(j);
                    res.push_back(temp);
                }
            }
        }
        return res;
    }
};