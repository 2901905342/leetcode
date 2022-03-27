//编写一个算法来判断一个数 n 是不是快乐数。
//「快乐数」定义为：
//对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
//然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
//如果 可以变为  1，那么这个数就是快乐数。
//如果 n 是快乐数就返回 true ；不是，则返回 false 。


//////////////思路、
/////题目中说了会 无限循环，那么也就是说求和的过程中，sum会重复出现，这对解题很重要！
//当我们遇到了要快速判断一个元素是否出现集合里的时候，就要考虑哈希法了。
#include "myhead.h"
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>m_set;
        int sum = 0;
        while (1) {
            // 求解下一个n的值
            while (n) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            n = sum;
            sum = 0;
            if (n == 1)  return true;
            if (m_set.count(n)) return false;
            else m_set.insert(n);
        }
    }
};