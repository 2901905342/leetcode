//给你一个字符串 s ，将该字符串中的大写字母转换成相同的小写字母，返回新的字符串

#include "myhead.h"
class Solution {
public:
    string toLowerCase(string s) {
        for (int i = 0; i < s.size(); i++) {
            int k = (int)s[i];
            if (k >= 65 && k <= 90) {
                s[i] = (char)(k + 32);
            }
        }
        return s;
    }
};