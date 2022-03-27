//给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
//说明：本题中，我们将空字符串定义为有效的回文串。

/// <summary>
/// ////////////////////////思路 ： 双指针
/// </summary>
/// 
#include "myhead.h"
class Solution {
public:
    bool isPalindrome(string s) {
        vector<int> all;
        for (int i = 0; i < s.size(); i++) {
            int temp = (int)s[i];
            if ((temp >= 97 && temp <= 122) || (temp >= 48 && temp <= 57)) { //小写字母和数字如实输入
                all.push_back(temp);
            }
            if (temp >= 65 && temp <= 90) {
                all.push_back(temp + 32);
            }
        }
        bool flag = true;
        int i = 0;
        int j = all.size() - 1;
        while (i < j) {
            if (all[i] != all[j]) {
                return !flag;
            }
            i++;
            j--;
        }
        return flag;
    }
};