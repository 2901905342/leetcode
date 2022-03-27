//当一个字符串 s 包含的每一种字母的大写和小写形式 同时 出现在 s 中，就称这个字符串 s 是 美好 字符串。
//比方说，"abABB" 是美好字符串，因为 'A' 和 'a' 同时出现了，且 'B' 和 'b' 也同时出现了。
//然而，"abA" 不是美好字符串因为 'b' 出现了，而 'B' 没有出现。
//给你一个字符串 s ，请你返回 s 最长的 美好子字符串 。
//如果有多个答案，请你返回 最早 出现的一个。如果不存在美好子字符串，请你返回一个空字符串。
///1 <= s.length <= 100
///s 只包含大写和小写英文字母。


////  直接暴力解法，注意用二进制存储字母是否出现的写法
///进阶的分治和滑动窗口就算了

#include "myhead.h"
class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.size();
        int MaxPos = 0;
        int MaxLen = 0;
        for (int i = 0; i < n; i++) {
            int upper = 0;
            int lower = 0;
            for (int j = i; j < n; j++) {
                if (islower(s[j])) {
                    lower |= 1 << (s[j] - 'a');
                }
                else {
                    upper |= 1 << (s[j] - 'A');
                }
                if (upper == lower && j - i + 1 > MaxLen) {
                    MaxPos = i;
                    MaxLen = j - i + 1;
                }
            }
        }
        return s.substr(MaxPos, MaxLen);
    }
};