//给你一个字符串 s ，根据下述规则反转字符串：
//所有非英文字母保留在原有位置。
//所有英文字母（小写或大写）位置反转。
//返回反转后的 s 。

//提示
//1 <= s.length <= 100
//s 仅由 ASCII 值在范围[33, 122] 的字符组成
//s 不含 '\"' 或 '\\'

#include "myhead.h"
////////思想1：简单模拟
class Solution {
public:
    string reverseOnlyLetters(string s) {
        string res;
        vector<int> index;
        for (int i = 0; i < s.size(); i++) {
            bool flag1 = (s[i] - 'A' >= 0) && (s[i] - 'A' <= 25);
            bool flag2 = (s[i] - 'a' >= 0) && (s[i] - 'a' <= 25);
            if (flag1 || flag2) res += s[i];
            else index.push_back(i);
        }
        reverse(res.begin(), res.end());
        for (auto i : index) {
            res.insert(i, 1, s[i]);
        }
        return res;
    }
};

//////思想2：双指针
//我们使用 left 指针从左边开始扫描字符串 s，right 指针从右边开始扫描字符串 ss。如果两个指针都扫描到字母
//且 left < right，那么交换s[left] 和 s[right]，然后继续进行扫描；
// 否则表明反转过程结束，返回处理后的字符串。
//值得注意的是使用isalpha函数可以判断字符是否为字母，属于ctype.h头文件；但也包含在iostream头文件下

class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        while (true) {
            while (left < right && !isalpha(s[left])) { // 判断左边是否扫描到字母
                left++;
            }
            while (right > left && !isalpha(s[right])) { // 判断右边是否扫描到字母
                right--;
            }
            if (left >= right) {
                break;
            }
            swap(s[left], s[right]);
            left++;
            right--;
        }
        return s;
    }
};

