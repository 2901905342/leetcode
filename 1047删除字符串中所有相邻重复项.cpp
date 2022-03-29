//给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。
//在 S 上反复执行重复项删除操作，直到无法继续删除。
//在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。



/////思路1  直接模拟，每次找到两个相邻且相同的字母，就直接删掉/////
///  缺点：  效率低，运行时间长  ///

#include "myhead.h"
class Solution {
public:
    string removeDuplicates(string s) {
        int i = 1;
        while (i < s.size()) {
            if (s[i - 1] == s[i]) {
                s.erase(i - 1, 2);//从位置i-1开始删除两个元素
                i = max(1, i - 2);
            }
            else i++;
        }
        return s;
    }
};


//// 思路2 ：用栈模拟  ///////////////////
class Solution {
public:
    string removeDuplicates(string s) {
        string result;
        for (char ch : s) {
            if (result.empty() || result.back() != ch) {
                result.push_back(ch);
            }
            else {
                result.pop_back();
            }
        }
        return result;
    }
};

