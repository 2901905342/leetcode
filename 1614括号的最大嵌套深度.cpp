//类似地，可以定义任何有效括号字符串 S 的 嵌套深度 depth(S)：
//
//depth("") = 0
//depth(C) = 0，其中 C 是单个字符的字符串，且该字符不是 "(" 或者 ")"
//depth(A + B) = max(depth(A), depth(B))，其中 A 和 B 都是 有效括号字符串
//depth("(" + A + ")") = 1 + depth(A)，其中 A 是一个 有效括号字符串
//例如：""、"()()"、"()(()())" 都是 有效括号字符串（嵌套深度分别为 0、1、2），而 ")(" 、"(()" 都不是 有效括号字符串 。
//给你一个 有效括号字符串 s，返回该字符串的 s 嵌套深度 。

/// <summary>
/// 简单题
/// </summary>

#include "myhead.h"

class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int res = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '(') count++;
            if (s[j] == ')')  count--;
            if (count > res) {
                res = count;
            }
        }
        return res;
    }
};