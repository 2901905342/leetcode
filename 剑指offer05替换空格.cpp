//请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

/////直接模拟
#include "myhead.h"
class Solution {
public:
    string replaceSpace(string s) {
        string res;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                res += "%20";
            }
            else res += s[i];
        }
        return res;
    }
};