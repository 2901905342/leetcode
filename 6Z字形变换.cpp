//将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。
//比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：
//P   A   H   N
//A P L S I I G
//Y   I   R
//之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。
//请你实现这个将字符串进行指定行数变换的函数：
//string convert(string s, int numRows);


///////思路：模拟，时间复杂度o(n+numRows)，空间复杂度o(n),n为s,size() 
#include "myhead.h"
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s; //当只有一行时直接返回s
        vector<string> res(numRows);
        string ans;
        int i = 0;
        int flag = -1;
        for (auto c : s) {  
            res[i] += c;  //把每个字符 c 填入对应行 res[i]
            if (i == 0 || i == numRows - 1) flag = -flag; //在达到 ZZ 字形转折点时，执行反向。
            i += flag;   //更新当前字符 c 对应的行索引
        }
        for (auto re : res) {
            ans += re;
        }
        return ans;
    }
};