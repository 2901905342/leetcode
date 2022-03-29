//给你一个字符串 s ，字符串的「能量」定义为：只包含一种字符的最长非空子字符串的长度。
//请你返回字符串的能量。



////////典型的快慢指针做法//////////
#include "myhead.h"
class Solution {
public:
    int maxPower(string s) {
        int n = s.size();
        if (n == 0 || n == 1) return n;
        int low = 0;
        int right = 1;
        int res = 1;
        while (right < n) {
            if (s[low] == s[right]) {
                int temp = right - low + 1;
                res = max(res, temp);
            }
            else {
                low = right;
            }
            right++;
        }
        return res;

    }
};