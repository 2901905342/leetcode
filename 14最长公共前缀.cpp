//编写一个函数来查找字符串数组中的最长公共前缀。
//如果不存在公共前缀，返回空字符串 ""。

//1 <= strs.length <= 200
//0 <= strs[i].length <= 200
//strs[i] 仅由小写英文字母组成

////////////思路：一共可分为三种，横向遍历，纵向遍历，分治（划分子问题）
///横向遍历和分治的代码都比较复杂，且效率与纵向遍历一致，这里只收集纵向遍历的写法
/////纵向遍历，先比较每一列

//// 官方写法更为巧妙，能比本人写法在时间复杂度上能少一个O（m)
#include "myhead.h"
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int m = strs.size();
        int m_len = strs[0].size();
        int indexm = 0;
        for (int i = 0; i < m; i++) {
            if (m_len > strs[i].size()) {
                m_len = strs[i].size();
                indexm = i;        //此处是获取最短字符串的长度以及该字符串在vector中的位置
                                   //这一步保证后续遍历时不会出现索引溢出的情况
            }
        }
        for (int j = 0; j < m_len; j++) {
            char temp = strs[0][j];
            for (int i = 0; i < m; i++) {
                if (strs[i][j] != temp) return strs[indexm].substr(0, j);  
            }   //最长公共前缀一定不会超过最短字符串，即最长公共前缀是最短字符串的子串
        }
        return strs[indexm];
    }
};