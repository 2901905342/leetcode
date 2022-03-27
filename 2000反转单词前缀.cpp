//给你一个下标从 0 开始的字符串 word 和一个字符 ch 。
//找出 ch 第一次出现的下标 i ，反转 word 中从下标 0 开始、直到下标 i 结束（含下标 i ）的那段字符。
//如果 word 中不存在字符 ch ，则无需进行任何操作。
//例如，如果 word = "abcdefd" 且 ch = "d" ，那么你应该 反转 从下标 0 开始、直到下标 3 结束（含下标 3 ）。
//结果字符串将会是 "dcbaefd" 。
//返回 结果字符串 。

////////思路：简单模拟，注意官方对reverse函数区间是左闭右开的用法

#include "myhead.h"

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int flag = 0;
        int right = 0;
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == ch) {
                flag = 1;
                right = i;
                break;
            }
        }
        if (!flag) return word;
        int left = 0;
        while (left < right) {
            swap(word[left], word[right]);
            left++;
            right--;
        }
        return word;
    }
};


class Solution {
public:
    string reversePrefix(string word, char ch) {
        int index = word.find(ch); //查找ch第一次出现的位置
        if (index != -1) {
            reverse(word.begin(), word.begin() + index + 1);
        }
        return word;
    }
};

