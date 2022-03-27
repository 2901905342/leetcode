//给定一个整数 num，将其转化为 7 进制，并以字符串形式输出。

/////思路：求7进制数，就是对num用7取余，然后num=num/7，如此循环直到num=0;从下向上取余数即可
#include "myhead.h"
class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return to_string(0);
        string negative;
        string res;
        if (num < 0) {
            num = -num;
            negative = '-';
        }
        while (num) {
            res = to_string(num % 7) + res;
            num /= 7;
        }
        return negative + res;
    }
};