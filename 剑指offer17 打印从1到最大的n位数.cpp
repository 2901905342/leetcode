//输入数字 n，按顺序打印出从 1 到最大的 n 位十进制数。
//比如输入 3，则打印出 1、2、3 一直到最大的 3 位数 999。

///////简单模拟
#include "myhead.h"
class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> res;
        int count = 0;  //存储最大的n位数
        int i = 9;
        while (n) {
            count += i;
            i *= 10;
            n--;
        }
        for (int i = 1; i <= count; i++) {
            res.push_back(i);
        }
        return res;
    }
};